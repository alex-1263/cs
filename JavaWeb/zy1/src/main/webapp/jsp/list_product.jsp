<%@ page language="java" import="java.util.*" pageEncoding="UTF-8" contentType="text/html; charset=UTF-8"%>
<%@ page import="blog.dao.GoodDao" %>
<%@ page import="blog.entity.Good" %>
<%@ page import="com.digital.dao.GoodsDao" %>
<%@ page import="com.digital.beans.Goods" %>

<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://"
			+ request.getServerName() + ":" + request.getServerPort()
			+ path + "/";

%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="zh-CN" xml:lang="zh-CN">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>数码商城产品介绍</title>
	<link type="text/css" rel="stylesheet" href="../style/main.css" />
	<script type="text/javascript">
		function checkAddCarForm() {
			if (document.getElementById("num").value.length <= 0)
				alert("请输入购买数量！");
			else
				document.addCarForm.submit();
		}
	</script>
</head>
<body>
<div id="header">
	<div id="header_inside">
		<p>
			<img src="../css/images/header1.jpg" alt="" usemap="#Map" />
		</p>
		<div id="menu">
			<ul>
				<li><a href="<%=path %>/jsp/index.jsp" class="btn_active">网站首页</a></li>
				<li><a href="<%=path %>/product/list_product.jsp">商品列表</a></li>
				<li><a href="#">热卖产品</a></li>
				<li><a href="#">最新活动</a></li>
				<li><a href="#">关于我们</a></li>
				<li><a href="#">联系我们</a></li>
			</ul>
		</div>
	</div>
</div>
<div id="allcontent">
	<div id="sidebar2">
		<h2>
			商品分类
		</h2>
		<ul>
			<li class="list1">
				<a href="#">手机专区</a>
			</li>
			<li>
				<a href="#">存话费送手机</a>
			</li>
			<li class="list1">
				<a href="#">笔记本电脑</a>
			</li>
			<li>
				<a href="#">数码相机</a>
			</li>
			<li class="list1">
				<a href="#">单反相机</a>
			</li>
			<li>
				<a href="#">DV摄像机</a>
			</li>
			<li class="list1">
				<a href="#">平板电脑</a>
			</li>
			<li>
				<a href="#">摄影配件</a>
			</li>
			<li class="list1">
				<a href="#">其他商品</a>
			</li>
		</ul>
		<div id="starpro2">
			<h1>
				我们的明星产品
			</h1>

			<p>
				<a href=""><img src="../product/images/iphone12pro.jpg" alt="" />	</a>
			</p>
			<p>
				Apple iPhone 12Pro 黑色 移动联通电信4G手机 双卡双待
			</p>

			<p>
				<a href=""><img src="../product/images/apple USB.jpg" alt="" />	</a>
			</p>
			<p>
				Apple 20W USB-C手机充电器插头 充电头 适配器适用iPhone 12 iPad
			</p>

			<p>
				<a href="#"><img src="../product/images/apple airpod.jpg" alt="" />	</a>
			</p>
			<p>
				Apple AirPods Pro 主动降噪无线蓝牙耳机 适用iPhone/iPad/Apple
			</p>

			<p>
				<a href=""><img src="../product/images/apple iMac.jpg" alt="" />	</a>
			</p>
			<p>
				Apple iMac 【2020新款 】27 英寸5K屏 3.1GHz 六核十代
			</p>

		</div>
	</div><!-- end of sidebar2 -->
	<div id="productinfodiv">
		<%
			int gid = Integer.parseInt(request.getParameter("gid"));
			GoodsDao goodDao= new GoodsDao() {
				@Override
				public List<Goods> getGoodsList() {
					return null;
				}

				@Override
				public Goods getInstance() {
					return null;
				}

				@Override
				public Goods getInstance(Goods goods) {
					return null;
				}

				@Override
				public Goods getGoodsById() {
					return null;
				}

				@Override
				public Goods getGoodsById(Goods goods) {
					return null;
				}
			};
			Goods getinfo = GoodsDao.getinfo(gid);
		%>
		<div id="productimg">
			<img src="<%=getinfo.getPic()%>" width="310" height="310" /><!-- 这里是商品图片 -->
		</div>
		<div id="tips" style="float: left; width: 430px; height: 200px">
			<form action="" method="post" name="addCarForm">
				<h1><%=getinfo.getName()%></h1>
				<input type="hidden" name="flag" value="add" />
				<input type="hidden" name="id" value="" />
				<input type="hidden" name="code" value="" />
				<input type="hidden" name="name" value="" />
				<input type="hidden" name="price" value="" />
				<input type="hidden" name="sale" value="" />
				<input type="hidden" name="pic" value="" />
				<ul>
					<li style="list-style: none;" class="bt"></li>

					<li style="list-style: none;" class="text">
						价&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;格：<%=getinfo.getPrice()%></li>
					<li style="list-style: none;" class="text">
						促销信息：直降<%=getinfo.getSale()%></li>
					<li style="list-style: none;" class="bt">
						库&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;存：<%=getinfo.getNum()%></li>
					<li
							style="list-style: none; font-size: 13px; font-family: 黑体; color: red;">
						我要买:
						<input type="text" name="num" id="num" size="3">
						件
					</li>
				</ul>
				<img hspace="50" src="../css/images/gwc.png" onclick="javascript:checkAddCarForm();" s>
			</form>
		</div>
		<div class="cl"></div>
		<div id="main2">

			<div id="intro" style="margin-top: 10px">
				<%=getinfo.getIntro()%>
				<div class="cl"></div>
			</div>
			<div class="cl"></div>
		</div>
	</div>
	<%
	%>
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
			<p><img src="../css/images/title3.gif" alt="" width="100" height="30" /></p>
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
	<p>
		copyright &copy;.All Rights Reserverd. Design form XXX
	</p>
</div>
</body>
</html>