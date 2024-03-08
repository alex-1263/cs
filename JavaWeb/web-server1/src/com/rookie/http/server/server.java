package com.rookie.http.server;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;


public class server {
    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(8082);
        for(;;){
            Socket socket = ss.accept();
            Thread t =new Handler(socket);
            t.start();
        }
    }
}

class Handler extends Thread{
    Socket socket;

    public Handler(Socket socket){
        this.socket =socket;
    }

    @Override
    public void run() {
        try {
            InputStream inputStream = this.socket.getInputStream();
            OutputStream outputStream =this.socket.getOutputStream();
            handle(inputStream,outputStream);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void handle(InputStream input, OutputStream output) throws IOException {
        var reader = new BufferedReader(new InputStreamReader(input, StandardCharsets.UTF_8));
        var writer = new BufferedWriter(new OutputStreamWriter(output, StandardCharsets.UTF_8));

        //读取http请求
        boolean isok =false;
        String first = reader.readLine();
        System.out.println(first);
        if(first.startsWith("GET / HTTP/1.")){
            isok=true;
        }
        for(;;){
            String header =reader.readLine();
            System.out.println(header);
            if(header.isEmpty()){
                break;
            }
        }
        if(!isok){
            writer.write("404 NOT DOUND\r\n");
            writer.write("Content Length:0\r\n");
            writer.flush();
        }else{
            String data ="<html><body><h1>Hello world!</h1></body></html1>";
            int length =data.getBytes(StandardCharsets.UTF_8).length;
            writer.write("HTTP/1.1 200 OK\r\n"); // 200 404 500
            writer.write("Content-Length"+length+"\r\n");
            writer.write("Content-Type:text/html;charset=utf-8\r\n");
            writer.write("\r\n");
            writer.write(data);
            writer.flush();
        }
    }
}