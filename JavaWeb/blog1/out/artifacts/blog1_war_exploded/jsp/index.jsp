<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="../css/css.css">
</head>
<body>
<form id="form1">
    <div id="wrapper">
        <%@ include file="../jsp/top.jsp" %>
        <div id="content">
            <div id="mainContent">

                <ul class="news-list-ul clearfix">
                    <li><a href="#">深足教练组：说我们买球是侮辱 朱广沪常</a></li>
                    <li><a href="#">省政府500万悬赏建业登顶 球员：遗憾主场</a></li>
                    <li><a href="#">洪元朔：北京人的脸就看你们了 最后一哆</a></li>
                    <li><a href="#">临界冠军京城夺票总动员 球迷夺冠！让所</a></li>
                    <li><a href="#">一纸传真暗含申花处理态度 国足征调社</a></li>
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
        <%@ include file="../jsp/left.jsp" %>
        <%@ include file="../jsp/bottom.jsp" %>
    </div>
</form>
</body>
</html>