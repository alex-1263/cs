<%--
  Created by IntelliJ IDEA.
  User: 123
  Date: 2023/10/10 0010
  Time: 17:24
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    session.removeAttribute("username");
    Cookie cookie = new Cookie("username","");
    cookie.setMaxAge(0);
    response.addCookie(cookie);
    out.print("<script type='text/javascript'>alert('退出成功')</script>");
    response.setHeader("refresh", "0;url=index.jsp");
%>
</body>
</html>
