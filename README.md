# 基于Poco库和sqlite的SQL练习

    使用Poco库的原因是Poco库的Data组件，使得sql的操作在不同数据库间在代码编写上有一致性，符合ODBC的规范。
    使用sqlite的原因是，嵌入式或者边缘计算一般数据库的体量不是很大，使用sqlite的机会比mysql要多，同时数据的迁移也比mysql方便多。
    如果是在使用mysql的情况下，请在系统资源富足的情况下，尽量使用容器技术，将mysql的数据以数据卷的形式释放出来，方便维护。

    primary key、unique key、foreign key的区别
    都是数据库的约束类型，为了确保数据的准确性和可靠性。除去key外还有一个NOT NULL的非空约束，
    约束类型            |名称         |作用                                     |应用场景
    primary key       |主键         |字段值唯一且非空，用来唯一标识表中的每一行记录    |在任何需要独一无二、易于识别每条记录的场合，如订单号、用户id等
    unique key        |唯一键       |字段唯一可以为空，确保每一行的指定列或者列组合    |电子邮件、身份证号码等
                                    是唯一的，用来约束那些虽然不是主键但是要保持
                                    唯一的字段
    foreign key       |外键         |用于表示多个表的关系，确保表之间数据的一致性和    |比如订单表中的customer_id外键指向客户表的id主键，用于关联每个订单与下单的客户
                                    完整性。通过引用另外一个表的主键来实现两表之间
                                    的连接和数据一致性维护。通常用于实现数据库的关系
                                    模型，

## 新建sqlite3数据库

    linux安装sqlite3环境参考 
    新建数据库：
    sqlite3 mydata.db
    进入sqlite的mydata数据库命令行后，输入
    .databases
    显示数据库(主要是为了使生成的mydata.db文件能够保存到当前目录，如果不做这步或者生成一个表，直接退出的话，mydata.db就会消失)，就可以输入退出命令
    .quit 
    
    后面的操作主要是依靠ide的数据库插件和代码来进行sql的练习

## 练习

    所有的操作都是在一个测试文件的main中以 注册Data组件、打开数据库、操作、注销Data组件 4步。其中操作是作练习的主要代码段

### 查询
#### ch1

    查询，有条件查询(升降序(order by  asc/desc)、条件筛选(where and/or))

#### ch2

    聚合函数 min/max/count/sum/avg
    
#### ch3

    分组 group by 将查询结果按照特定的字段进行分组，然后进行统计(用聚合函数进行统计计算)

#### ch4

    表关联 join，出现的原因是，数据量往往会很大，需要将一个大表拆分成几个小的表，表与表之间通过key来进行关联
    txx1 inner/left/right/outer join txx2  on txx1.xx=txx2.xx

#### ch5

    限制查询输出条目 limit
    使用场景是 1、尝试看下数据的表结构是什么样的
             2、和排序一起使用，得到排名前几的信息
    
#### ch6

    存在 having 与where的使用比较相近，都是用来筛选子集的，但是having需要和group by 一起使用

#### ch7

    窗口函数，两类
    1、聚合5类函数，min max sum avg count 等
    2、特殊函数，
        排序 
            row_number 行号
            rank dense_rank 排序 (dense rank 值相同的并列排名)
        取值
            first_value()返回当前第一行的数据
            last_value()返回当前最后一行的数据
            lag 返回当前行前几行的数据
                LAG(Expression, OffSetValue, DefaultVar) OVER (
                    PARTITION BY [Expression]
                    ORDER BY Expression [ASC|DESC]
                );
            lead 返回当前行的后几行的数据
                LEAD(Expression, OffSetValue, DefaultVar) OVER (
                    PARTITION BY [Expression]
                    ORDER BY Expression [ASC|DESC]
                );

    <窗口函数> over (partition by <用于分组的列名>

                order by <用于排序的列名>
                range between xxx and xxx <用于分组后取子集>)
    **窗口函数有点难的，可以多次练习**
        
### 插入

#### ch8

    insert 插入
        insert into table xxx(col1,col2,...,colx) values(val1,val2,...,valx)

### 更新
    
    update 更新
        update table set col=val where condition

### 删除

    delete 删除
        delete from table where condition

### 条件表达式

    使用场景：基于数值类型的colume生成新的colume

    1、if(condition，true_value,false_value)

    2、case when condtion1 then value1 when condition2 then value2 else result end

### count

    进行记录条目数的计算，通常还会与 distinct 一起使用来剔除指为null的列

### as

    将结果的列名进行重命名；或者对查询获得的底表(结果)进行重命名

### union/union all
    
    与 jion 类似，都是两个表的联合查询，不同的是，jion是列数增加，丰富单个记录的属性数量；union是行数增加，丰富记录的条目数，所以有个前提是两个表的列数必须一致，且位置相同的列的数据类型必须一致。
    union 会删除重复的行
    union all 会保留重复的行

### concat/concat_ws(concat_ws就是concat with separator)

    文本函数，将多个字符串进行拼接

### 日期

    可以参考 https://www.runoob.com/sql/sql-dates.html
    时间函数可以不用记得那么多，因为不同的数据库框架，能够使用的日期函数数量并不一样，可以在自己的ide的数据库组件中尝试实验后，再决定怎么使用。
    
### 视图

    视图语句通常使用在数据库的建表sql语句中，在code代码段中并不常见

    CREATE VIEW view_name AS
    SELECT column1, column2, ...
    FROM table_name
    WHERE condition;

