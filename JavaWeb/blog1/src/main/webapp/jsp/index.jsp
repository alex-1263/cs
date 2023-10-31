<%@ page language="java" contentType="text/html; charset=UTF-8"
		 pageEncoding="UTF-8"%>
<%@ page import="com.blog.dao.BlogDao"%>
<%@ page import="com.blog.dao.impl.BlogDaoImpl"%>
<%@ page import="com.blog.entity.Blog"%>
<%@ page import="java.util.*"%>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="../css/css.css">
</head>
<body>
<form id="form1">
	<div id="wrapper">
		<%@ include file="../jsp/top.jsp"%>
		<div id="content">
			<div id="mainContent">

				<ul class="news-list-ul clearfix">

					<%
						BlogDao blogDao = new BlogDaoImpl() {
							@Override
							public Blog getInstance(Blog blog) {
								return null;
							}
						};
						List<Blog> list = blogDao.getBlogList();
						for(Blog blog:list){
					%>
					<li><a href="blogInfo.jsp?id=<%=blog.getBid()%>"> <%=blog.getBid()%>  <%=blog.getTitle()%></a></li>
					<%
						}
					%>



				</ul>
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
						response.sendRedirect("jsp/login.jsp");
				%>


				<h2>每周推荐</h2>
				<p>《雷声与蝉鸣》是香港诗人梁秉钧创作的第一本诗集，也是他的代表作，被认为是现代华文诗坛的经典之作。</p>
			</div>
		</div>
		<%@ include file="../jsp/left.jsp"%>
		<%@ include file="../jsp/bottom.jsp"%>
	</div>
</form>
</body>
</html>