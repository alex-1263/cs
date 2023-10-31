<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<%@ page import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="com.blog.dao.impl.BlogDaoImpl"%>
<%@page import="com.blog.dao.BlogDao"%>
<%@page import="com.blog.entity.Blog"%>
<html>
<head>

<link rel="stylesheet" type="text/css" href="../css/css.css">
	<title></title>
</head>
<body>

	<%
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		int uid = Integer.parseInt(request.getParameter("id")); //读取传递的id值
		Blog blog = new Blog();
		blog.setBid(uid);
		//System.out.println("bid="+request.getParameter("id"));
		BlogDao blogDao = new BlogDaoImpl() {
			public void setBlog(Blog blog) {
				this.blog = blog;
			}

			public Blog getBlog() {
				return blog;
			}

			private Blog blog;

			@Override
			public Blog getInstance(Blog blog) {
				this.blog = blog;
				return null;
			}
		};
		blog = blogDao.getBlogById(blog);
	%>

	<form id="form1">
		<div id="wrapper">
			<%@ include file="top.jsp"%>
			<div id="content">
				<div id="mainContent">


					<div class="text-box">
						<div class="text-box-tbg">
							<div class="text-box-bbg">
								<div class="article-box">

									<h2><%=blog.getTitle()%></h2>
									<div class="source-bar">
										发布时间：<%=blog.getTitle()%></div>
									<div class="article-content">
										<span class="article-summary"><b>摘要：<%=blog.getSummary()%></b></span>
										<p><%=blog.getContent()%></p>
									</div>
								</div>
							</div>
						</div>
					</div>


				</div>
				<div id="secondaryContent">

					<%
						String username = (String) session.getAttribute("username");
						if (username != null) {
							out.println("欢迎你   " + username);
					%>
					<a href="loginOut.jsp">注销</a></br>
					<%
						} else
							response.sendRedirect("login.jsp");
					%>


					<h2>每周推荐</h2>
					<p>《雷声与蝉鸣》是香港诗人梁秉钧创作的第一本诗集，也是他的代表作，被认为是现代华文诗坛的经典之作。</p>
				</div>
			</div>
			<%@ include file="left.jsp"%>
			<%@ include file="bottom.jsp"%>
		</div>
	</form>
</body>
</html>