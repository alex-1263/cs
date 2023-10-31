<%--
  Created by IntelliJ IDEA.
  User: 123
  Date: 2023/10/10 0010
  Time: 14:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="com.digital.dao.impl.UserDaoImpl" %>
<%@ page import="java.util.Date" %>
<%@ page import="com.digital.beans.User" %>
<%@ page import="com.digital.dao.UserDao" %>
<%@ page import="com.digital.dao.impl.UserDaoImpl" %>
<%@ page import="java.sql.PreparedStatement" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    request.setCharacterEncoding("utf-8");
    response.setCharacterEncoding("utf-8");
    String username = request.getParameter("username");//账号
    String password = request.getParameter("password");//密码
    String realname = request.getParameter("realname");//真实姓名
    String sex = request.getParameter("sex");//性别
    String address = request.getParameter("address");//地址
    String question = request.getParameter("question");//密保
    String answer = request.getParameter("answer");//答案
    String email = request.getParameter("email");//邮箱
    Date time = new Date();//创建时间
    User user = new User();
    user.setUsername(username);
    user.setPassword(password);
    user.setRealname(realname);
    user.setSex(sex);
    user.setAnswer(answer);
    user.setAddress(address);
    user.setQuestion(question);
    user.setEmail(email);
    user.setTime(time);
    UserDao userDao = new UserDaoImpl() {
        @Override
        public boolean addUser(UserDao user) {
            return false;
        }

        @Override
        public int addUser(String username, String password, String sex, String realname, String amswer, String address, String question, String email, Date time) {
            return 0;
        }
    };
    boolean digital = userDao.addUser(user);
    if (digital) {
        Cookie cookie = new Cookie("username", username);
        response.addCookie(cookie);
        session.setAttribute("username", username);
        cookie.setPath("/");
        //response.sendRedirect("index.jsp");
        response.sendRedirect(request.getContextPath() + "/jsp/index.jsp");
    } else {
        out.print("<script type='text/javascript'>alert('注册失败')</script>");
        response.setHeader("refresh", "2;url=register.jsp");
    }
%>
</body>
</html>
