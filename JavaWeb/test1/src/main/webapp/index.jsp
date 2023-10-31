<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="zh-CN" xml:lang="zh-CN">
    <head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
		<title>数码商城网站</title>
		<link type="text/css" rel="stylesheet" href="style/main.css" />
		<script type="text/javascript" src="js/imagerollover.js"></script>
    </head>
    <body>
   
	<div id="header">
		<div id="header_inside">
	    <p><img src="images/header1.jpg" alt="" usemap="#Map" />
		</p>		
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
	<div id="right">
		<div id="login">
	 
			<form id="loginform" name="loginform" method="post" action="" >
				<div><strong>登录名：</strong><input name="username" id="txtUser" size="15" value="" /></div>
				<div><strong>密　码：</strong><input name="password" type="password" id="txtPassword" size="15" value="" /></div>
				
				<div><input type="submit" value="登录" name="submit" class="picbut" />　
				<input name="reg" type="button" value="注册用户" class="picbut" onclick="javascript:location.href=('register.jsp');" />
				</div>
				
				<div><font color=red size=3></font></div>
			 </form>
	
		
		</div>
		<div class="news">
			<p><img src="images/title3.gif" alt="" width="100" height="30" /></p>
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
	<div id="content">
	<div id="adv">
		<SCRIPT language=javascript>
			var m_nPageInitTime = new Date();
			var MainTopRoll = new xwzRollingImageTrans("IMG_MAIN_TOP_ROLL_DETAIL", "IMGS_MAIN_TOP_ROLL_THUMBNAIL");
			MainTopRoll.addItem("","images/shower_01.jpg");
			MainTopRoll.addItem("","images/shower_02.jpg");
			MainTopRoll.addItem("","images/shower_03.jpg");
			MainTopRoll.addItem("","images/shower_04.jpg");
		</SCRIPT>
	  <TABLE cellSpacing=0 cellPadding=0 width=575 align=center>
		<TBODY>
		  <TR>
			<TD id=IDS_DIV_MAIN_TOP_ROLL_DETAIL width=500 height=235><IMG  class=clssMainRoll height=235   src="images/shower_01.jpg"   width=500 border=0 name=IMG_MAIN_TOP_ROLL_DETAIL></TD>
			<!--
			<TD width=283 bgcolor="#F4F4F4" style="DISPLAY: none">
			-->
			<TD width=283 bgcolor="#F4F4F4"><TABLE cellSpacing=0 cellPadding=0 align=center>
				<TBODY>
				  <TR>
					<TD align=right height=60><IMG style="DISPLAY: none"	height=5 src="" width=9 align=absMiddle border=0 name=IMGS_MAIN_TOP_ROLL_THUMBNAIL><IMG 
						style="CURSOR: pointer" onclick=MainTopRoll.alterImage(0) 	src="images/mini_01.jpg" border=0></TD>
				  </TR>
				  <TR>
					<TD align=right height=60><IMG style="DISPLAY: none" 	height=5 src="" width=9 align=absMiddle border=0 name=IMGS_MAIN_TOP_ROLL_THUMBNAIL><IMG 
						style="CURSOR: pointer" onclick=MainTopRoll.alterImage(1) src="images/mini_02.jpg" border=0></TD>
				  </TR>
				  <TR>
					<TD align=right height=60><IMG style="DISPLAY: none"  height=5 src="" width=9 align=absMiddle border=0 name=IMGS_MAIN_TOP_ROLL_THUMBNAIL><IMG 
						style="CURSOR: pointer" onclick=MainTopRoll.alterImage(2) src="images/mini_03.jpg" border=0></TD>
				  </TR>
				  <TR>
					<TD align=right height=60><IMG style="DISPLAY: none" height=5 src="" width=9 align=absMiddle border=0 name=IMGS_MAIN_TOP_ROLL_THUMBNAIL><IMG 
						style="CURSOR: pointer" onclick=MainTopRoll.alterImage(3) src="images/mini_04.jpg" border=0></TD>
				  </TR>
				</TBODY>
			</TABLE></TD>
		  </TR>
		</TBODY>
	  </TABLE>
    <SCRIPT language=JavaScript>
		MainTopRoll.Index =  parseInt('0');
		MainTopRoll.install();
    </SCRIPT>
	</div>
	<div id="advlist">
	<div>
		<h2 class="title01">最新活动</h2>
		<p><a href="#"><img src="images/iphone12.jpg" alt="" width="75" height="50"></a></p>
		<h3><a href="#">iphone12Pro</a>， ￥8499.00</h3>
		<p> 【联通直营】Apple 苹果 iPhone 12 Pro 全网通5G智能手机苹果手机苹果12手机新品iPhone12pro……</p>
	</div>
	<div>
		<h2 class="title02">热卖产品</h2>
		<p><a href="#"><img src="images/canoneos5d_small.jpg" alt="" width="75" height="50"></a></p>
		<h3><a href="#">佳能（Canon） EOS 6D Mark II 单反套机 </a>￥16199.00</h3>
		<p>佳能（Canon） EOS 6D Mark II 套机EF 24-105mm f/4L IS II USM 经典不止于轻，开启全画幅单反新篇章</p>
	</div>
	<div>
		<h2 class="title03">新品上架</h2>
		<p><a href="#"><img src="images/ipad_small.jpg" alt="" width="75" height="50"></a></p>
		<h3> <a href="#">苹果IPAD2020</a>  ￥2699.00</h3>
		<p> 【春节发货】2020新款 Apple/苹果 iPad 10.2英寸平板电脑 学生上网课 8便携式掌上电脑 顺丰发货 学习平板</p>
	</div>
	</div>
		
	</div>

	</div>
		<div id="footer">
			<p>copyright &copy;.All Rights Reserverd. Design form XXX </p>
		</div>
    </body>
</html>
