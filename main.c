/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:37:33 by xzhen             #+#    #+#             */
/*   Updated: 2025/02/20 13:37:53 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>   // 用于打开文件
#include <unistd.h>  // 用于 read 函数

int main() {
    int fd = open("test.txt", O_RDONLY);  // 打开一个测试文件
    if (fd == -1) {
        return 1;  // 如果打开失败，则返回错误
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {  // 每次读取一行
        write(1, line, ft_strlen(line));  // 输出到标准输出
        free(line);  // 记得释放内存
    }

    close(fd);  // 关闭文件描述符
    return 0;
}
