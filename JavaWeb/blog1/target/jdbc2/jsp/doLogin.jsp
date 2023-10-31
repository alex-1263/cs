<%@page import="com.blog.dao.UserDao"%>
<%@ page import="com.blog.entity.User" %>
<%@ page import="com.blog.dao.impl.UserDaoImpl" %>
<%@ page import="java.util.Date" %>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Insert title here</title>
</head>
<body>
<%
    request.setCharacterEncoding("utf-8");
    response.setCharacterEncoding("utf-8");
    String username=request.getParameter("username");  //读取用户名
    String password=request.getParameter("password");
    User user = new User();
    user.setUsername(username);
    user.setPassword(password);
    UserDao userDao= new UserDaoImpl() {
        @Override
        public int addUser(String username, String password, String sex, String email, Date time) {
            return 0;
        }
    };

    boolean b = userDao.getUser(user);
    if(b){
        session.setAttribute("username", username);
        Cookie cookie=new Cookie("username", username);
        cookie.setPath("/");
        response.addCookie(cookie);
        response.sendRedirect(request.getContextPath()+"/jsp/index.jsp");
        //response.sendRedirect("index.jsp");
    }
    else{
        out.print("<script type='text/javascript'>alert('登录失败')</script>");
        response.setHeader("refresh", "2;url=login.jsp");
    }
%>
</body>
</html>