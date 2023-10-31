package com.blog.dao;



import com.blog.entity.User;

import java.util.Date;

public interface UserDao {
	public boolean addUser(User user) ;
	public boolean getUser(User user) ;

	int addUser(String username, String password, String sex, String email, Date time);
}
