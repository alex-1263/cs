<%@ page import="com.digital.dao.impl.UserDaoImpl" %>
<%@ page import="com.digital.beans.User" %>
<%@ page import="com.digital.dao.UserDao" %>
<%@ page import="com.digital.dao.impl.UserDaoImpl" %>
<%@ page import="java.util.Date" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
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
    String username = request.getParameter("username");
    String password = request.getParameter("password");
    User user  = new User();
    user.setUsername(username);
    user.setPassword(password);
    UserDao userDao = new UserDaoImpl(){
        @Override
        public boolean addUser(UserDao user) {
            return false;
        }

        @Override
        public int addUser(String username, String password, String sex, String realname, String amswer, String address, String question, String email, Date time) {
            return 0;
        }
    };
    boolean digital = userDao.getUser(user);
    if (digital) {
        session.setAttribute("username", username);
        Cookie cookie = new Cookie("username", username);
        response.addCookie(cookie);
        out.print("<script type='text/javascript'>alert('登录成功')</script>");
        response.setHeader("refresh", "0;url=indexfull.jsp");
    } else {
        out.print("<script type='text/javascript'>alert('登录失败')</script>");
        response.setHeader("refresh", "2;url=index.jsp");
    }
%>
</body>
</html>
