/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:45:21 by xzhen             #+#    #+#             */
/*   Updated: 2025/02/20 13:45:33 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>   // 用于打开文件
#include <unistd.h>  // 用于 read 函数

int main() {
    int fd1 = open("test1.txt", O_RDONLY);  // 打开第一个文件
    int fd2 = open("test2.txt", O_RDONLY);  // 打开第二个文件
    if (fd1 == -1 || fd2 == -1) {
        return 1;  // 如果打开文件失败，则返回错误
    }

    char *line;
    
    // 读取第一个文件的内容
    while ((line = get_next_line(fd1)) != NULL) {
        write(1, line, ft_strlen(line));  // 输出到标准输出
        free(line);  // 记得释放内存
    }
    
    // 读取第二个文件的内容
    while ((line = get_next_line(fd2)) != NULL) {
        write(1, line, ft_strlen(line));  // 输出到标准输出
        free(line);  // 记得释放内存
    }

    close(fd1);  // 关闭第一个文件描述符
    close(fd2);  // 关闭第二个文件描述符

    return 0;
}
