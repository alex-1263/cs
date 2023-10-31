package com.blog.dao;


import java.sql.*;
import java.util.Date;

public class UserDao extends BaseDao {

    //链接建立？
    public boolean addUser(String username, String password, String sex, String email, Date time) {

        getConnection();
        String sql = "insert into user(username,password,sex,email,time)values(?,?,?,?,?)";
        try {
            preparedStatement = connection.prepareStatement(sql);
            preparedStatement.setString(1, username);
            preparedStatement.setString(2, password);
            preparedStatement.setString(3, sex);
            preparedStatement.setString(4, email);
            preparedStatement.setTimestamp(5, new Timestamp(time.getTime()));
            int i = preparedStatement.executeUpdate();
            if (i > 0) {
                return true;
            } else
                return false;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            closeResource();
        }

    }

    //数据的注册
}
