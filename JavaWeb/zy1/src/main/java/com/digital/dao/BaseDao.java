package com.digital.dao;

import java.sql.*;
public class BaseDao {
    public Connection connection;
    public PreparedStatement preparedStatement;
    public ResultSet resultset;

    public boolean getConnection() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            String url = "jdbc:mysql://127.0.0.1:3306/digital?serverTimezone=GMT%2B8";
            connection = DriverManager.getConnection(url, "root", "123456");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            return false;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public boolean closeResource(){
        try {
            if(resultset!=null){
                resultset.close();
            }
            if(preparedStatement!=null){
                preparedStatement.close();
            }
            if(connection!=null){
                connection.close();
            }
        } catch (SQLException e) {
           e.printStackTrace();
           return false;
        }
        return true;

    }

}
