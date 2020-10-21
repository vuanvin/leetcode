## Git 的使用

增加文件或文件夹：

```shell
git add .gitignore

# add directory with all files in it
git add Python3/

# add all
git add .            
git add --all
git add -A
```



提交：

```
git commit -m "commit massage"
```



远程提交：

```
git push leetcode
```



**1) 远程仓库相关命令**

检出仓库：$ **git** clone **git**://github.com/jquery/jquery.**git**

查看远程仓库：$ **git** remote -v

添加远程仓库：$ **git** remote add [name] [url]

删除远程仓库：$ **git** remote rm [name]

修改远程仓库：$ **git** remote set-url --**push**[name][newUrl]

拉取远程仓库：$ **git** pull [remoteName] [localBranchName]

推送远程仓库：$ **git push** [remoteName] [localBranchName]