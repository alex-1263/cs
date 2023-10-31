package com.blog.dao.impl;

import com.blog.dao.BaseDao;
import com.blog.dao.BlogDao;
import com.blog.entity.Blog;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;


public abstract class BlogDaoImpl extends BaseDao implements BlogDao{

	public List<Blog> getBlogList(){
		List<Blog> list=new ArrayList<Blog>();
		try {
			getConnection();
			String sql="SELECT * FROM blog";
			pStatement=connection.prepareStatement(sql);		
			rSet=pStatement.executeQuery();
			while(rSet.next()){
				Blog blog1 = new Blog();
				blog1.setBid(rSet.getInt("bid"));
				blog1.setUid(rSet.getInt("uid"));
				blog1.setTitle(rSet.getString("title"));
				blog1.setSummary(rSet.getString("summary"));
				blog1.getContent(rSet.getString("content"));
				blog1.setTime(rSet.getTimestamp("time"));
				list.add(blog1);
				//System.out.println("读出一条信息");
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
			throw new RuntimeException(e);
		}finally {
			closeResource();	
		}


		return list;
	}

	public Blog getInstance() {
		return getInstance(null);
	}

	public Blog getInstance(Blog blog) {
		return null;
	}

	public Blog getBlogById(Blog blog) {
		getConnection();
		Blog blog1 = new Blog();
		String sql = "select * from blog where bid = ?";
		try {
			pStatement = connection.prepareStatement(sql);
			pStatement.setInt(1,blog.getBid());
			rSet = pStatement.executeQuery();
			if (rSet.next()){
				blog1.setBid(rSet.getInt("bid"));
				blog1.setUid(rSet.getInt("uid"));
				blog1.setTime(rSet.getString("title"));
				blog1.setSummary(rSet.getString("summary"));
				blog1.setContent(rSet.getString("content"));
				blog1.setTime(rSet.getTime("time"));

			}
			return blog1;
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}finally {
			closeResource();
		}

	}
}
