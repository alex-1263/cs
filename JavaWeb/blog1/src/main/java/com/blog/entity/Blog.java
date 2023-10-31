package com.blog.entity;

import java.util.Date;

public class Blog {
	private static Blog blog1;
	private int bid;
	private int uid;
	private String title;
	private  String summary;
	private String content;
	private Date time;

	private Blog(String summary) {
		this.summary = summary;
	}

	public Blog() {

	}

	public static Blog getBlog1() {
		return blog1;
	}

	public static void setBlog1(Blog blog1) {
		Blog.blog1 = blog1;
	}

	public static Blog createBlog(String summary) {
		return new Blog(summary);
	}

	public int getBid() {
		return bid;
	}
	public void setBid(int bid) {
		this.bid = bid;
	}

	public void setUid(int uid) {
		this.uid = uid;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String getSummary() {
		return summary;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	public Date getTime() {
		return time;
	}
	public void setTime(Date time) {
		this.time = time;
	}


	public void setSummary(String summary) {
		this.summary = summary;
	}

	public void getContent(String content) {
		this.content = content;
	}

	public void setTime(String title) {
		this.title = title;
	}

	public int getUid() {
		return uid;
	}
}
