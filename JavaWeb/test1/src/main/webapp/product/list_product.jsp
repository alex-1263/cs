<%@ page language="java" import="java.util.*" pageEncoding="UTF-8" contentType="text/html; charset=UTF-8"%>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";

%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html >
    <head>
	
	<title>数码商城产品列表</title>
	<link type="text/css" rel="stylesheet" href="../style/main.css" />
    </head>
    <body>
	<div id="header">
		<div id="header_inside">
			<p><img src="../images/header1.jpg" alt="" usemap="#Map" />	</p>		
			<div id="menu">
				<ul>
					<li><a href="#" class="btn_active">网站首页</a></li>
					<li><a href="#">商品列表</a></li>
					<li><a href="#">热卖产品</a></li>
					<li><a href="#">最新活动</a></li>
					<li><a href="#">关于我们</a></li>
					<li><a href="#">联系我们</a></li>
				</ul>
			</div>
		</div>
	</div>
	
	<div id="allcontent">
	<div id="sidebar">
		<h2>商品分类</h2>
		<ul>
			<li class="list1"><a href="#">手机专区</a></li>
			<li><a href="#">存话费送手机</a></li>
			<li class="list1"><a href="#">笔记本电脑</a></li>
			<li><a href="#">数码相机</a></li>
			<li class="list1"><a href="#">单反相机</a></li>
			<li><a href="#">DV摄像机</a></li>
			<li class="list1"><a href="#">平板电脑</a></li>
			<li><a href="#">摄影配件</a></li>
			<li class="list1"><a href="#">其他商品</a></li>
		</ul>
	</div>
	<div id="pro_list1">

			<div class="productslist">
				<div>
				<a href="#"><img src="" width="170" height="128" /></a><!-- 这里是商品图片 -->
				</div>
				<strong>这里是商品名称<br />
				经济高效，超低成本！<br /></strong>
				四叶草价：<span class="price"> ￥</span><br />
				促销信息：<span class="onsale" >直降 ￥ </span >
			</div>

	</div><!-- end of pro_list1 -->
	<div id="right">
		<div id="login">
	 
			<form id="loginform" name="loginform" method="post" action="" >
				<div><strong>登录名：</strong><input name="txtUser" id="txtUser" size="15" value="" /></div>
				<div><strong>密　码：</strong><input name="txtPassword" type="password" id="txtPassword" size="15" value="" /></div>
				
				<div><input type="submit" value="登录" name="submit" class="picbut" />　
				<input name="reg" type="button" value="注册用户" class="picbut" onclick="javascript:location.href=('register.jsp');" />
				</div>
				
				<div><font color=red size=3></font></div>
			 </form>
	
		
		</div>
		<div class="news">
			<p><img src="../images/title3.gif" alt="" width="100" height="30" /></p>
			<ol>
				<li>24小时送达迟一天退10元</li>
				<li>支付宝金账户购物全场98折</li>
				<li>用建行卡购物全场98折</li>
				<li>工行分期付款0.3%/月手续费</li>
				<li>7天内无条件退货</li> 
				<li>运输造成的损害我们承担损失 </li>
			</ol>
		</div>
	</div>
	
	</div>
	<div id="footer">
		<p>copyright &copy;.All Rights Reserverd. Design form XXX </p>
	</div>
    </body>
</html>
