<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.util.*"%>
<%@ page import="java.text.SimpleDateFormat"%>
<html>
<head>

	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
   	<link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
   	<link href="../css/signin.css" rel="stylesheet">
   	<script src="../jquery/jquery-1.9.1.min.js"></script>
   	<script src="../bootstrap/js/bootstrap.min.js"></script>
   	<title>注册</title>
</head>
<body>

<div class="container">
      <form class="form-signin" action="doRegister.jsp" method="post">
        <h3 class="form-signin-heading">用户注册</h3>
        <label for="inputUsername" class="sr-only">用户名</label>
        <input type="text" id="username" name="username" class="form-control" placeholder="用户名" required autofocus>
        <label for="inputPassword" class="sr-only">密码</label>
        <input type="password" id="password" name="password" class="form-control" placeholder="密码" required>
        <label for="inputPassword" class="sr-only">确认密码</label>
        <input type="password" id="Repassword" name="Repassword" class="form-control" placeholder="确认密码" required>
         <label for="inputEmail" class="sr-only">电子邮箱</label>
        <input type="email" id="email" name="email" class="form-control" placeholder="邮箱" required>
        
        <div class="checkbox">
          	<label for="inputSex" class="sr-only">性别</label>
         	<input type="radio" name="sex" value="男" checked="checked" />男
         	<input	type="radio" name="sex" value="女" />女
        </div>
        <div >
        <button class="btn btn-lg btn-primary btn-block2" type="submit">注册</button>   
        <button class="btn btn-lg btn-primary btn-block2" type="reset">重置</button>
        </div>
      </form>
      

    </div> <!-- /container -->
	
</body>
</html>