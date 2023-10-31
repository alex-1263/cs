package com.blog.dao.impl;

import java.sql.SQLException;
import java.sql.Timestamp;

import com.blog.dao.BaseDao;
import com.blog.dao.UserDao;
import com.blog.entity.*;


public abstract class UserDaoImpl extends BaseDao implements UserDao{

	public boolean addUser(User user) {
		try {
			getConnection();
			String sql="insert into user(username,password,sex,email,time) values(?,?,?,?,?)";
			pStatement=connection.prepareStatement(sql);
			pStatement.setString(1, user.getUsername());
			pStatement.setString(2, user.getPassword());
			pStatement.setString(3, user.getSex());
			pStatement.setString(4, user.getEmail());
			pStatement.setTimestamp(5, new Timestamp(user.getTime().getTime()));
			int i=pStatement.executeUpdate();
			if (i<=0){
				return false;
			}else {
				return true;
			}
	
		}  catch (SQLException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
			throw new RuntimeException(e);
		}finally {			
			closeResource();
		}
	}
	
	public boolean getUser(User user) {
		try {
			getConnection();
			String sql="SELECT * FROM user WHERE username= ? and password= ?";
			pStatement=connection.prepareStatement(sql);		
			pStatement.setString(1, user.getUsername());
			pStatement.setString(2, user.getPassword());
			rSet=pStatement.executeQuery();
			if(rSet.next()){
				return true;
			}else {
				return false;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
			throw new RuntimeException(e);
		}finally {
			closeResource();	
		}
	}


}

