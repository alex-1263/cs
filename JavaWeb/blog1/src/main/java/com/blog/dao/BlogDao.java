    package com.blog.dao;

    import com.blog.entity.Blog;

    import java.util.List;

    public interface BlogDao {
        public <blog> List<blog> getBlogList();
        public Blog getInstance(Blog blog);

        Blog getBlogById(Blog blog);
    }
s