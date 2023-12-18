import sqlite3
conn=sqlite3.connect('test.db')
c=conn.cursor()
c.execute("CREATE TABLE category(id int primary ,sort int,name text)")
c.execute("CREATE TABLE book(id int primary ,sort int,name text,price real,category int,FOREIGN KEY (category) REFERENCES category(id))")
conn.commit()
sql3="CREATE TABLE if not exists category(id int primary ,sort int,name text)"
c.execute(sql3)
sql4="select name from sqlite_master where type='table'"
c.execute(sql4)
print(c.fetchall())
sql5="select name from sqlite_master where type='?'"
c.execute(sql5,('table',))
print(c.fetchall())

sql6="INSERT INTO category VALUES(1,1,'Python')"
c.execute(sql6)
sql7="INSERT INTO category VALUES(?,?,?)"
c.execute(sql7,(2,2,'Java'))
sql8="INSERT INTO book VALUES(?,?,?,?,?)"
books=[(1,1,'疯狂Python讲义',88.8,1),(2,1,'疯狂Java讲义',109.0,2)]
c.execute(sql8,books)
sql9=""
c.execute("select * from book")
print(c.fetchall())
conn.commit()
c.execute("select name from category order by sort")
print(c.fetchall())
c.execute("select * from book inner join category on book.category=category.id and category.name='Python'")
print(c.fetchall())
for row in c.execute("select name,price from book order by sort"):
    print(row)
conn.commit()
conn.close()
conn=sqlite3.connect('test.db')
#将book表中id为1的记录的price字段更新为86.4
conn.execute("update book set price=86.4 where id=1")
#查询book表中id为1的记录的price记录
cursor=conn.execute("select * from book where id=1")
print(cursor.fetchone())
#查询book表中id为2的记录的记录
cursor=conn.execute("select * from book where id=2")
print(cursor.fetchone())
#将book表中id为2的记录删除
conn.execute("delete from book where id=2")
#查询book表中所有记录
cursor=conn.execute("select * from book")
print(cursor.fetchall())
conn.commit()
conn.close()
conn=sqlite3.connect('test.db')
c=conn.cursor()
c.execute("select * from sqlite_master where type='table' order by name") 
print(c.fetchall())
c.execute("PRAGMA table_info('book')")
print(c.fetchall())
c.execute("drop table category")
#验证
c.execute("select * from sqlite_master where type='table' order by name")
print(c.fetchall())
conn.commit()
conn.close()