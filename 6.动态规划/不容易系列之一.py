"""
@Time:2018/2/22 14:25
@Author:xuzhongyou
"""
#给网友写了n封信，求全装错的方式个数，其实可以推导出一个错排公式F(n) = F(n-1)(n-1)+(n-1)F(n-2)
#分析得到错排公式。根据等值来分为两类