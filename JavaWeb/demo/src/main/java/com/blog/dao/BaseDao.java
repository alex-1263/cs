package com.blog.dao;


import java.sql.*;

public class BaseDao {
    //加载驱动
    public Connection connection;
    public PreparedStatement preparedStatement;
    public ResultSet resultset;

    public boolean getConnection() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            String url = "jdbc:mysql://127.0.0.1:3306/blog?serverTimezone=GMT%2B8";
            connection = DriverManager.getConnection(url, "root", "123456");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);

        } catch (SQLException e) {
            throw new RuntimeException(e);

        } finally {
            return true;
        }
    }

    public boolean closeResource() {
        try {
            if (resultset != null) {
                resultset.close();
            }
            if (preparedStatement != null) {
                preparedStatement.close();
            }
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            return true;
        }
    }


}
