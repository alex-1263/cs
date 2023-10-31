<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page import="com.blog.dao.UserDao" %>


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
	UserDao userdao = new UserDao();
	boolean b = userdao.addUser(username,password,sex,email,new Date());
	if(b){

	}else{

	}

%>


</body>
</html>
