package com.digital.dao.impl;

import com.digital.beans.User;
import com.digital.dao.BaseDao;
import com.digital.dao.UserDao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.util.Date;

public abstract class UserDaoImpl extends BaseDao implements UserDao {

    private PreparedStatement pStatement;

    @Override
    public boolean addUser(User user){
        try {
            getConnection();
            String sql="insert into user(username,password,realname,sex,address,question,answer,email,time) values(?,?,?,?,?,?,?,?,?)";
            pStatement=connection.prepareStatement(sql);
            pStatement.setString(1, user.getUsername());
            pStatement.setString(2, user.getPassword());
            pStatement.setString(3, user.getRealname());
            pStatement.setString(4, user.getSex());
            pStatement.setString(5, user.getAddress());
            pStatement.setString(6, user.getQuestion());
            pStatement.setString(7, user.getAnswer());
            pStatement.setString(8, user.getEmail());
            pStatement.setTimestamp(9,new Timestamp(user.getTime().getTime()));
            int i=pStatement.executeUpdate();
            if (i<=0){
                return  false;
            }else {
                return true;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            closeResource();
        }
    }

    private PreparedStatement preparedStatement;
    private User user;

    public UserDaoImpl() {

    }

    @Override
    public boolean getConnection() {
        super.getConnection();
        return false;
    }

    @Override
    public boolean closeResource() {
        return super.closeResource();
    }

    @Override
    public boolean getUser(User user) {
        try {
            getConnection();
            String sql="SELECT * FROM user WHERE username= ? and password= ?";
            PreparedStatement pStatement = connection.prepareStatement(sql);
            pStatement.setString(1, user.getUsername());
            pStatement.setString(2, user.getPassword());
            ResultSet rSet = pStatement.executeQuery();
            if (rSet.next()){
                return true;
            }else {
                return false;

            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            closeResource();
        }
    }

    public PreparedStatement getPreparedStatement() {
        return preparedStatement;
    }

    public void setPreparedStatement(PreparedStatement preparedStatement) {
        this.preparedStatement = preparedStatement;
    }

    public abstract boolean addUser(UserDao user);

    public int addUser() {
        return addUser(null, null, null, null, null, null, null, null, null);
    }

    public abstract int addUser(String username, String password, String sex, String realname, String amswer, String address, String question, String email, Date time);

    public User getUser() {
        return user;
    }

    public void setUser() {
        setUser(null);
    }

    public void setUser(User user) {
        this.user = user;
    }
    
}
