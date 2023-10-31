package com.blog.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class BaseDao {

	public Connection connection=null;
	public PreparedStatement pStatement=null;
	public ResultSet rSet=null;
	public boolean getConnection() {
			try {
				Class.forName("com.mysql.jdbc.Driver");
				String url="jdbc:mysql://127.0.0.1:3306/blog?serverTimezone=GMT%2B8";
				//String url="jdbc:mysql://127.0.0.1:3307/blog?serverTimezone=GMT%2B8";
				connection=DriverManager.getConnection(url, "root", "123456");
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return false;
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return false;
			}
			return true;
	}
	
	public boolean closeResource() {
		try {
			if(rSet!=null)
				rSet.close();
			if(pStatement!=null)
				pStatement.close();
			if(connection!=null)
				connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}
		return true;
	}
	
}
