import socket
import os
import datetime

# Server configuration
HOST = "127.0.0.1"  # Localhost
PORT = 8080         # Port to listen on
STATIC_DIR = "./static"  # Directory to serve files from


def get_current_time():
    """Returns the current timestamp."""
    return datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")


def log_request(client_ip, request, status_code):
    """Logs the HTTP request."""
    print(f"[{get_current_time()}] [{client_ip}] \"{request}\" {status_code}")


def handle_request(request):
    """Handles an HTTP GET request."""
    try:
        # Parse the request
        lines = request.split("\r\n")
        first_line = lines[0]
        method, path, _ = first_line.split()

        if method != "GET":
            return "HTTP/1.1 405 Method Not Allowed\r\n\r\n", 405

        # Map the requested path to a file in the static directory
        if path == "/":
            path = "/index.html"
        file_path = STATIC_DIR + path

        # Check if the file exists
        if not os.path.isfile(file_path):
            error_page = "<h1>404 Not There</h1>"
            response = (
                "HTTP/1.1 404 Not Found\r\n"
                f"Content-Length: {len(error_page)}\r\n"
                "Content-Type: text/html\r\n"
                "\r\n"
                + error_page
            )
            return response, 404

        # Serve the file
        with open(file_path, "rb") as file:
            content = file.read()
        content_type = "text/html" if file_path.endswith(".html") else "application/octet-stream"
        response = (
            "HTTP/1.1 200 OK\r\n"
            f"Content-Length: {len(content)}\r\n"
            f"Content-Type: {content_type}\r\n"
            "\r\n"
        )
        return response.encode() + content, 200

    except Exception as e:
        # Handle unexpected errors
        error_page = f"<h1>500 Internal Server Error</h1><p>{e}</p>"
        response = (
            "HTTP/1.1 500 Internal Server Error\r\n"
            f"Content-Length: {len(error_page)}\r\n"
            "Content-Type: text/html\r\n"
            "\r\n"
            + error_page
        )
        return response, 500


def start_server():
    """Starts the HTTP server."""
    # Create a socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen(10)
    print(f"Server is listening on {HOST}:{PORT}...")

    while True:
        # Accept a client connection
        client_socket, client_address = server_socket.accept()
        client_ip = client_address[0]
        print(f"Connection received from {client_ip}")

        try:
            # Receive the HTTP request
            request = client_socket.recv(1024).decode()
            print(f"Request: {request}")

            # Handle the request and generate a response
            response, status_code = handle_request(request)

            # Log the request
            log_request(client_ip, request.split("\r\n")[0], status_code)

            # Send the response
            client_socket.sendall(response.encode() if isinstance(response, str) else response)

        except Exception as e:
            print(f"Error handling request: {e}")

        finally:
            # Close the client connection
            client_socket.close()


if __name__ == "__main__":
    # Ensure the static directory exists
    if not os.path.isdir(STATIC_DIR):
        print(f"Static directory '{STATIC_DIR}' does not exist. Please create it and add test files.")
    else:
        start_server()
