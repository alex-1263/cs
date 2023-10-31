<%@page import="com.blog.dao.UserDao"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page import="com.blog.entity.User" %>
<%@ page import="com.blog.dao.impl.UserDaoImpl" %>


<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>


	<title>My JSP 'doUserCreate.jsp' starting page</title>

	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

</head>

<body>
<%
	request.setCharacterEncoding("utf-8");
	response.setCharacterEncoding("utf-8");
	String username=request.getParameter("username");  //读取用户名
	String password=request.getParameter("password");
	String email=request.getParameter("email");
	String sex=request.getParameter("sex");

	Date time=new Date();
	User user = new User();
	user.setUsername(username);
	user.setPassword(password);
	user.setSex(sex);
	user.setEmail(email);
	user.setTime(time);
	UserDao userDao = new UserDaoImpl() {
		@Override
		public int addUser(String username, String password, String sex, String email, Date time) {
			return 0;
		}
	};
	boolean b = userDao.addUser(user);
	if (b){
		Cookie cookie = new Cookie("username",username);
		response.addCookie(cookie);
		session.setAttribute("username",username);
		response.sendRedirect("index.jsp");
	}else {
		out.println("<script type='text/javascript'>alert('注册失败')</script>");
		response.setHeader("refresh", "2;url=register.jsp");
	}

%>


</body>
</html>
