<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
   	<link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
   	<link href="css/signin.css" rel="stylesheet">
   	<script src="../jquery/jquery-1.9.1.min.js"></script>
   	<script src="../bootstrap/js/bootstrap.min.js"></script>
	<title>登录</title>
</head>
<%
Cookie[] cookies=request.getCookies();
String user="";
if(cookies!=null && cookies.length!=0){
	for(int i=0;i<cookies.length;i++)
		if(cookies[i].getName().equals("username"))
			user=cookies[i].getValue();
}
%>
<body>
 <div class="container">
      <form class="form-signin" action="doLogin.jsp" method="post">
        <h2 class="form-signin-heading">请登录</h2>
        <label for="inputUsername" class="sr-only">用户名</label>
        <input type="text" id="username" name="username" class="form-control" placeholder="用户名" value="<%=user %>" required autofocus>
        <label for="inputPassword" class="sr-only">密码</label>
        <input type="password" id="password" name="password" class="form-control" placeholder="密码" required>
        <div class="checkbox">
          <label>
            <input type="checkbox" value="remember-me"> Remember me
          </label>
        </div>
        <button class="btn btn-lg btn-primary btn-block" type="submit">登录</button>
        <div> 没有账号，请<a href="register.jsp">注册</div>
               
      </form>

    </div> <!-- /container -->
</body>
</html>