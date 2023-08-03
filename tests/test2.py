import socket

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = "0.0.0.0"  # Bind to all available interfaces
    port = 12346     # Choose a suitable port number

    server_socket.bind((host, port))
    server_socket.listen(1)

    print("Waiting for a connection...")
    # if manual break, use Ctrl+C
    #  and end the server
    # if KeyboardInterrupt:
    #     server_socket.close()
    #     print("Server closed")
    conn, addr = server_socket.accept()
    print(f"Connection established with {addr}")

    while True:
        data = conn.recv(1024)
        if not data:
            break
        print(f"Received message: {data.decode()}")

    conn.close()

if __name__ == "__main__":
    start_server()
