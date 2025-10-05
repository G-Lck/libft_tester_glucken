/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:28:40 by glucken           #+#    #+#             */
/*   Updated: 2025/10/01 15:28:40 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_tester_glucken.h"
#define RED   "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
const char	*const_charstar_tests[] = {
	"AbcA",
	"",
	"abc",
	"120",
	"\0",
	"abcd"
};
char	*charstar_tests[] = {
	"AbcA",
	"",
	"abc",
	"120",
	"\0"
};
char	char_tests[] = {
	'a',
	'Z',
	'?',
	0
};
int		int_tests[] = {
	'a',
	'A',
	'0',
	' ',
	0,
	42,
	-1,
	700,
	'd'
};
size_t	size_t_tests[] = {
	4,
	'A',
	'0',
	' ',
	0,
	42,
	700
};
t_list	**lists_tests(void)
{
	t_list *node3 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node1 = malloc(sizeof(t_list));
	t_list *single_node = malloc(sizeof(t_list));
	t_list *null_node3 = malloc(sizeof(t_list));
	t_list *null_node2 = malloc(sizeof(t_list));
	t_list *null_node1 = malloc(sizeof(t_list));
	t_list *long10 = malloc(sizeof(t_list));
	t_list *long9 = malloc(sizeof(t_list));
	t_list *long8 = malloc(sizeof(t_list));
	t_list *long7 = malloc(sizeof(t_list));
	t_list *long6 = malloc(sizeof(t_list)); 
	t_list *long5 = malloc(sizeof(t_list));
	t_list *long4 = malloc(sizeof(t_list));
	t_list *long3 = malloc(sizeof(t_list));
	t_list *long2 = malloc(sizeof(t_list));
	t_list *long1 = malloc(sizeof(t_list));
	node3->content = "third"; node3->next = NULL;
	node2->content = "second"; node2->next = node3;
	node1->content = "first"; node1->next = node2;
	single_node->content = "only"; single_node->next = NULL;
	null_node3->content = NULL; null_node3->next = NULL;
	null_node2->content = "valid"; null_node2->next = null_node3;
	null_node1->content = NULL; null_node1->next = null_node2;
	long10->content = "node10"; long10->next = NULL;
	long9->content = "node9"; long9->next = long10;
	long8->content = "node8"; long8->next = long9;
	long7->content = "node7"; long7->next = long8;
	long6->content = "node6"; long6->next = long7;
	long5->content = "node5"; long5->next = long6;
	long4->content = "node4"; long4->next = long5;
	long3->content = "node3"; long3->next = long4;
	long2->content = "node2"; long2->next = long3;
	long1->content = "node1"; long1->next = long2;
	t_list **lists = malloc(sizeof(t_list *) * 6);
	lists[0] = node1;
	lists[1] = single_node;
	lists[2] = NULL;
	lists[3] = null_node1;
	lists[4] = long1;
	return lists;
}
char	f1_test(unsigned int i, char c)
{
	if(i == 0)
		return(c);
	else
		return('a');
}
char	f2_test(unsigned int i, char c)
{
	if(c == '0' && i < 10000)
		return('9');
	else
		return(c);
}
void	f3_test(unsigned int i, char* s)
{
	if(i != 0)
		s[i] = 'a';
}
void	f4_test(void *content)
{
	char *str = (char *)content;
	while (*str)
	{
		*str = *str + 1;
		str++;
	}
}
void	*f5_test(void *content)
{
	char *str = (char *)content;
	char *new_str = strdup(str);
	int	i;
	i = 0;
	if (!new_str)
		return NULL;
	while (new_str[i])
	{
		new_str[i] = str[i] + 1;
		i++;
	}
	return (void *)new_str;
}
void	del_content(void *content)
{
	free(content);
}
int		compare_int(int result, int expected)
{
	if (result == expected)
	{
		printf(GREEN "%d --> %d\n", result, expected);
		return(0);
	}
	else
	{
		printf(RED "%d --> %d\n", result, expected);
		return(1);
	}
}
int		compare_sizet(size_t result, size_t expected)
{
	if (result == expected)
	{
		printf(GREEN "%zu --> %zu\n", result, expected);
		return(0);
	}
	else
	{
		printf(RED "%zu --> %zu\n", result, expected);
		return(1);
	}
}
int		compare_charstar(char* result, char* expected)
{
	if (result == NULL && expected == NULL)
	{
		printf(GREEN "Both NULL\n");
		return 0;
	}
	else if (result == NULL)
	{
		printf(RED "ft NULL but not man\n");
		return 1;
	}
	else if (expected == NULL)
	{
		printf(RED "man NULL but not ft\n");
		return 1;
	}
	else if (strcmp(result, expected) == 0)
	{
		printf(GREEN "\"%s\" --> \"%s\"\n", result, expected);
		return 0;
	}
	else
	{
		printf(RED "\"%s\" --> \"%s\"\n", result, expected);
		return 1;
	}
}
int		compare_const_charstar(const char* result, const char* expected)
{
	if (result == expected)
	{
		printf(GREEN "\"%s\" --> \"%s\"\n", result, expected);
		return(0);
	}
	else
	{
		printf(RED "\"%s\" --> \"%s\"\n", result, expected);
		return(1);
	}
}
int		compare_mem(void *ft_mem, void *libc_mem, size_t n)
{
	size_t i = 0;
	if (memcmp(ft_mem, libc_mem, n) == 0)
	{
		while (i < n)
		{
			printf(GREEN "%02X --> %02X " RESET,
				   ((unsigned char *)ft_mem)[i],
				   ((unsigned char *)libc_mem)[i]);
			i++;
		}
		printf("\n");
		return (0);
	}
	else
	{
		while (i < n)
		{
			printf(RED "%02X --> %02X " RESET,
				   ((unsigned char *)ft_mem)[i],
				   ((unsigned char *)libc_mem)[i]);
			i++;
		}
		return (1);
	}
}
int		compare_ptr(void *ft_res, void *libc_res, void *base, size_t n)
{
	size_t i = 0;
	unsigned char *ft_ptr = (unsigned char *)ft_res;
	unsigned char *libc_ptr = (unsigned char *)libc_res;
	unsigned char *base_ptr = (unsigned char *)base;
	if (ft_res == libc_res)
	{
		while (i < n)
		{
			printf(GREEN "%02X --> %02X " RESET,
				   base_ptr[i],
				   base_ptr[i]);
			i++;
		}
		printf("\n");
		return 0;
	}
	else
	{
		while (i < n)
		{
			printf(RED "%02X --> %02X " RESET,
				   ft_ptr ? ft_ptr[i - (ft_ptr - base_ptr)] : 0,
				   libc_ptr ? libc_ptr[i - (libc_ptr - base_ptr)] : 0);
			i++;
		}
		printf("\n");
		return 1;
	}
}
int		compare_charstarstar(char **res, char **expected)
{
	size_t i = 0;
	if (!res && !expected)
		return 0;
	if (!res || !expected)
		return 1;
	while (expected[i])
	{
		if (!res[i])
			return 1;
		if (strcmp(res[i], expected[i]) != 0)
			return 1;
		i++;
	}
	if (res[i] != NULL)
		return 1;
	return 0;
}
int		compare_lists(t_list *ft_lst, t_list *expected_lst)
{
	while (ft_lst && expected_lst)
	{
		if (ft_lst->content != expected_lst->content)
		{
			printf(RED "%s --> %s\n" RESET,
				   (char *)ft_lst->content,
				   (char *)expected_lst->content);
			return (1);
		}
		else
		{
			printf(GREEN "%s --> %s\n" RESET,
				   (char *)ft_lst->content,
				   (char *)expected_lst->content);
		}
		ft_lst = ft_lst->next;
		expected_lst = expected_lst->next;
	}
	if (ft_lst || expected_lst)
	{
		printf(RED "Lists differ in length\n" RESET);
		return (1);
	}
	return (0);
}
int		compare_lists_mem(t_list *ft_lst, t_list *expected_lst)
{
	while (ft_lst && expected_lst)
	{
		if (strcmp(ft_lst->content, expected_lst->content) != 0)
		{
			printf(RED "%s --> %s\n" RESET,
				   (char *)ft_lst->content,
				   (char *)expected_lst->content);
			return (1);
		}
		else
		{
			printf(GREEN "%s --> %s\n" RESET,
				   (char *)ft_lst->content,
				   (char *)expected_lst->content);
		}
		ft_lst = ft_lst->next;
		expected_lst = expected_lst->next;
	}
	if (ft_lst || expected_lst)
	{
		printf(RED "Lists differ in length\n" RESET);
		return (1);
	}
	return (0);
}
void	test_ft_atoi(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For \"%s\": ", const_charstar_tests[i]);
		errors = errors + compare_sizet(ft_atoi(const_charstar_tests[i]), atoi(const_charstar_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_atoi OK\n\n"RESET);
	else
		printf(RED "ft_atoi FAIL\n"  RESET);
}
void	test_ft_bzero(void)
{
	size_t	len_charstar;
	size_t	i;
	int		errors;
	size_t	n;
	char	*charstar_test_ft;
	char	*charstar_test_man;
	len_charstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	errors = 0;
	while (i < len_charstar)
	{
		n = strlen(const_charstar_tests[i]);
		charstar_test_ft = malloc(sizeof(char) * (n + 1));
		strcpy(charstar_test_ft, const_charstar_tests[i]);
		charstar_test_man = malloc(sizeof(char) * (n + 1));
		strcpy(charstar_test_man, const_charstar_tests[i]);
		ft_bzero(charstar_test_ft, n);
		bzero(charstar_test_man, n);
		printf(RESET "\nFor %s: ", const_charstar_tests[i]);
		errors += compare_mem(charstar_test_ft, charstar_test_man, n);
		free(charstar_test_ft);
		free(charstar_test_man);
		i++;
	}
	if(errors == 0)
		printf(GREEN "\nft_bzero OK\n\n"RESET);
	else
		printf(RED "\nft_bzero FAIL\n\n" RESET);
}
void	test_ft_calloc(void)
{
	size_t	len;
	size_t	i;
	size_t	j;
	int		errors;
	len = sizeof(int_tests) / sizeof(int_tests[0]);
	i = 0;
	j = 0;
	errors = 0;
	while(i < len)
	{
		while (j < len)
		{
			printf(RESET "For %zu and %zu: ", size_t_tests[i], size_t_tests[j]);
			errors = errors + compare_mem(ft_calloc(size_t_tests[i], size_t_tests[j]), ft_calloc(size_t_tests[i], size_t_tests[j]), 1);
			j++;
		}
		j = 0;
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_calloc OK\n\n"RESET);
	else
		printf(RED "ft_calloc FAIL\n\n" RESET);
}
void	test_ft_isalnum(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(int_tests) / sizeof(int_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For %d: ", int_tests[i]);
		errors = errors + compare_int(ft_isalnum(int_tests[i]), isalnum(int_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_isalnum OK\n\n"RESET);
	else
		printf(RED "ft_isalnum FAIL\n\n" RESET);
}
void	test_ft_isalpha(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(int_tests) / sizeof(int_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For %d: ", int_tests[i]);
		errors = errors + compare_int(ft_isalpha(int_tests[i]), isalpha(int_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_isalpha OK\n\n"RESET);
	else
		printf(RED "ft_isalpha FAIL\n\n" RESET);
}
void	test_ft_isascii(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(int_tests) / sizeof(int_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For %d: ", int_tests[i]);
		errors = errors + compare_int(ft_isascii(int_tests[i]), isascii(int_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_isascii OK\n\n"RESET);
	else
		printf(RED "ft_isascii FAIL\n\n" RESET);
}
void	test_ft_isdigit(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(int_tests) / sizeof(int_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For %d: ", int_tests[i]);
		errors = errors + compare_int(ft_isdigit(int_tests[i]), isdigit(int_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_isdigit OK\n\n"RESET);
	else
		printf(RED "ft_isdigit FAIL\n\n" RESET);
}
void	test_ft_isprint(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(int_tests) / sizeof(int_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For %d: ", int_tests[i]);
		errors = errors + compare_int(ft_isprint(int_tests[i]), isprint(int_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_isprint OK\n\n"RESET);
	else
		printf(RED "ft_isprint FAIL\n\n" RESET);
}
int		sub_test_ft_itoa(int n, char* expected)
{
	char*  result;
	printf(RESET "For %d: ", n);
	result = ft_itoa(n);
	if (strcmp(result, expected) == 0)
	{
		printf(GREEN "\"%s\" --> \"%s\"\n", result, expected);
		return(0);
	}
	else
	{
		printf(RED "\"%s\" --> \"%s\"\n", result, expected);
		return(1);
	}
}
void	test_ft_itoa(void)
{
	int errors;
	int n;
	char* expected;
	errors = 0;
	// n = 0 //
	n = 0;
	expected = "0";
	errors = errors + sub_test_ft_itoa(n, expected);
	// lim min //
	n = -2147483648;
	expected = "-2147483648";
	errors = errors + sub_test_ft_itoa(n, expected);
	// lim max //
	n = 2147483647;
	expected = "2147483647";
	errors = errors + sub_test_ft_itoa(n, expected);
	// negative //
	n = -1234;
	expected = "-1234";
	errors = errors + sub_test_ft_itoa(n, expected);
	if(errors == 0)
		printf(GREEN "ft_itoa OK\n\n"RESET);
	else
		printf(RED "ft_itoa FAIL\n\n" RESET);
}
// t_list	**lists_compare_ft_lstadd_back(char* content)
// {
// 	t_list *node4 = malloc(sizeof(t_list));
// 	t_list *node3 = malloc(sizeof(t_list));
// 	t_list *node2 = malloc(sizeof(t_list));
// 	t_list *node1 = malloc(sizeof(t_list));
// 	t_list *single_node1 = malloc(sizeof(t_list));
// 	t_list *single_node = malloc(sizeof(t_list));
// 	t_list *null_node4 = malloc(sizeof(t_list));
// 	t_list *null_node3 = malloc(sizeof(t_list));
// 	t_list *null_node2 = malloc(sizeof(t_list));
// 	t_list *null_node1 = malloc(sizeof(t_list));
// 	t_list *long11 = malloc(sizeof(t_list));
// 	t_list *long10 = malloc(sizeof(t_list));
// 	t_list *long9 = malloc(sizeof(t_list));
// 	t_list *long8 = malloc(sizeof(t_list));
// 	t_list *long7 = malloc(sizeof(t_list));
// 	t_list *long6 = malloc(sizeof(t_list));
// 	t_list *long5 = malloc(sizeof(t_list));
// 	t_list *long4 = malloc(sizeof(t_list));
// 	t_list *long3 = malloc(sizeof(t_list));
// 	t_list *long2 = malloc(sizeof(t_list));
// 	t_list *long1 = malloc(sizeof(t_list));
// 	t_list *null1 = malloc(sizeof(t_list));
// 	t_list *null0 = malloc(sizeof(t_list));
// 	node4->content = content; node4->next = NULL;
// 	node3->content = "third"; node3->next = node4;
// 	node2->content = "second"; node2->next = node3;
// 	node1->content = "first"; node1->next = node2;
// 	single_node1->content = content; single_node1->next = NULL;
// 	single_node->content = "only"; single_node->next = single_node1;
// 	null1->content = content; null1->next = NULL;
// 	null0->content = NULL; null0->next = null1;
// 	null_node4->content = content; null_node4->next = NULL;
// 	null_node3->content = NULL; null_node3->next = null_node4;
// 	null_node2->content = "valid"; null_node2->next = null_node3;
// 	null_node1->content = NULL; null_node1->next = null_node2;
// 	long11->content = content; long11->next = NULL;
// 	long10->content = "node10"; long10->next = long11;
// 	long9->content = "node9"; long9->next = long10;
// 	long8->content = "node8"; long8->next = long9;
// 	long7->content = "node7"; long7->next = long8;
// 	long6->content = "node6"; long6->next = long7;
// 	long5->content = "node5"; long5->next = long6;
// 	long4->content = "node4"; long4->next = long5;
// 	long3->content = "node3"; long3->next = long4;
// 	long2->content = "node2"; long2->next = long3;
// 	long1->content = "node1"; long1->next = long2;
// 	t_list **lists = malloc(sizeof(t_list *) * 6);
// 	lists[0] = node1;
// 	lists[1] = single_node;
// 	lists[2] = null1;
// 	lists[3] = null_node1;
// 	lists[4] = long1;
// 	return lists;
// }
// void	test_ft_lstadd_back(void)
// {
// 	t_list **lists = lists_tests();
// 	t_list **lists_expected = lists_compare_ft_lstadd_back("new");
// 	int i = 0;
// 	int errors = 0;
// 	while (i <= 4)
// 	{
// 		t_list* expected;
// 		t_list*	result;
// 		result = lists[i];
// 		ft_lstadd_back(&result, ft_lstnew("new"));
// 		expected = lists_expected[i];
// 		printf(RESET "For %d\n", i);
// 		errors = errors + compare_lists(result, expected);
// 		i++;
// 	}
// 	if (errors == 0)
// 		printf(GREEN "\nft_lstadd_backOK\n\n"RESET);
// 	else
// 		printf(RED "\nft_lstadd_backFAIL\n\n" RESET);
// }
// t_list	**lists_compare_ft_lstadd_front(char* content)
// {
// 	t_list *node3 = malloc(sizeof(t_list));
// 	t_list *node2 = malloc(sizeof(t_list));
// 	t_list *node1 = malloc(sizeof(t_list));
// 	t_list *node0 = malloc(sizeof(t_list));
// 	t_list *single_node = malloc(sizeof(t_list));
// 	t_list *single_node0 = malloc(sizeof(t_list));
// 	t_list *null_node3 = malloc(sizeof(t_list));
// 	t_list *null_node2 = malloc(sizeof(t_list));
// 	t_list *null_node1 = malloc(sizeof(t_list));
// 	t_list *null_node0 = malloc(sizeof(t_list));
// 	t_list *long10 = malloc(sizeof(t_list));
// 	t_list *long9 = malloc(sizeof(t_list));
// 	t_list *long8 = malloc(sizeof(t_list));
// 	t_list *long7 = malloc(sizeof(t_list));
// 	t_list *long6 = malloc(sizeof(t_list));
// 	t_list *long5 = malloc(sizeof(t_list));
// 	t_list *long4 = malloc(sizeof(t_list));
// 	t_list *long3 = malloc(sizeof(t_list));
// 	t_list *long2 = malloc(sizeof(t_list));
// 	t_list *long1 = malloc(sizeof(t_list));
// 	t_list *long0 = malloc(sizeof(t_list));
// 	t_list *null0 = malloc(sizeof(t_list));
// 	node3->content = "third"; node3->next = NULL;
// 	node2->content = "second"; node2->next = node3;
// 	node1->content = "first"; node1->next = node2;
// 	node0->content = content; node0->next = node1;
// 	single_node->content = "only"; single_node->next = NULL;
// 	single_node0->content = content; single_node0->next = single_node;
// 	null0->content = content; null0->next = NULL;
// 	null_node3->content = NULL; null_node3->next = NULL;
// 	null_node2->content = "valid"; null_node2->next = null_node3;
// 	null_node1->content = NULL; null_node1->next = null_node2;
// 	null_node0->content = content; null_node0->next = null_node1;
// 	long10->content = "node10"; long10->next = NULL;
// 	long9->content = "node9"; long9->next = long10;
// 	long8->content = "node8"; long8->next = long9;
// 	long7->content = "node7"; long7->next = long8;
// 	long6->content = "node6"; long6->next = long7;
// 	long5->content = "node5"; long5->next = long6;
// 	long4->content = "node4"; long4->next = long5;
// 	long3->content = "node3"; long3->next = long4;
// 	long2->content = "node2"; long2->next = long3;
// 	long1->content = "node1"; long1->next = long2;
// 	long0->content = content; long0->next = long1;
// 	t_list **lists = malloc(sizeof(t_list *) * 6);
// 	lists[0] = node0;
// 	lists[1] = single_node0;
// 	lists[2] = null0;
// 	lists[3] = null_node0;
// 	lists[4] = long0;
// 	return lists;
// }
// void	test_ft_lstadd_front(void)
// {
// 	t_list **lists = lists_tests();
// 	t_list **lists_expected = lists_compare_ft_lstadd_front("new");
// 	int i = 0;
// 	int errors = 0;
// 	while (i <= 4)
// 	{
// 		t_list* expected;
// 		t_list*	result;
// 		result = lists[i];
// 		ft_lstadd_front(&result, ft_lstnew("new"));
// 		expected = lists_expected[i];
// 		printf(RESET "For %d\n", i);
// 		errors = errors + compare_lists(result, expected);
// 		i++;
// 	}
// 	if (errors == 0)
// 		printf(GREEN "\nft_lstadd_frontOK\n\n"RESET);
// 	else
// 		printf(RED "\nft_lstadd_frontFAIL\n\n" RESET);
// }
// void	test_ft_lstclear(void)
// {
// 	t_list *list1 = malloc(sizeof(t_list));
// 	t_list *list2 = malloc(sizeof(t_list));
// 	int     i;
// 	int     errors;
// 	list1->content = strdup("one");
// 	list1->next = list2;
// 	list2->content = strdup("two");
// 	list2->next = NULL;
// 	t_list *lists[2];
// 	lists[0] = list1;
// 	lists[1] = NULL;
// 	i = 0;
// 	errors = 0;
// 	while (i < 2)
// 	{
// 		ft_lstclear(&lists[i], del_content);
// 		if (lists[i] == NULL)
// 			printf(RESET "For %d: " GREEN "Test OK\n", i);
// 		else
// 		{
// 			printf(RESET "For %d: " RED "Test FAIL\n", i);
// 			errors++;
// 		}
// 		i++;
// 	}
// 	if (errors == 0)
// 		printf(GREEN "\nft_lstclearOK\n\n"RESET);
// 	else
// 		printf(RED "\nft_lstclearFAIL\n\n" RESET);
// }
// void	test_ft_lstdelone(void)
// {
// 	t_list *node = malloc(sizeof(t_list));
// 	node->content = malloc(10);
// 	node->next = NULL;
// 	ft_lstdelone(node, del_content);
// 	printf(GREEN "ft_lstdelone (check valgrind)\n");
// }
// void	test_ft_lstiteri(void)
// {
// 	t_list	*list1 = malloc(sizeof(t_list));
// 	t_list	*list2 = malloc(sizeof(t_list));
// 	t_list	*list1_exp = malloc(sizeof(t_list));
// 	t_list	*list2_exp = malloc(sizeof(t_list));
// 	int		errors;
// 	errors = 0;
// 	list2->content = strdup("two"); list2->next = NULL;
// 	list1->content = strdup("one"); list1->next = list2;
// 	list2_exp->content = strdup("uxp"); list2_exp->next = NULL;
// 	list1_exp->content = strdup("pof"); list1_exp->next = list2_exp;
// 	ft_lstiter(list1, f4_test);
// 	errors = errors + compare_lists_mem(list1, list1_exp);
// 	if (errors == 0)
// 		printf(GREEN "\nft_lstiteriOK\n\n"RESET);
// 	else
// 		printf(RED "\nft_lstiteriFAIL\n\n" RESET);
// }
// t_list	**lists_compare_ft_lstlast()
// {
// 	t_list *node3 = malloc(sizeof(t_list));
// 	t_list *single_node = malloc(sizeof(t_list));
// 	t_list *null_node3 = malloc(sizeof(t_list));
// 	t_list *long10 = malloc(sizeof(t_list));
// 	node3->content = "third"; node3->next = NULL;
// 	single_node->content = "only"; single_node->next = NULL;
// 	null_node3->content = NULL; null_node3->next = NULL;
// 	long10->content = "node10"; long10->next = NULL;
// 	t_list **lists = malloc(sizeof(t_list *) * 6);
// 	lists[0] = node3;
// 	lists[1] = single_node;
// 	lists[2] = NULL;
// 	lists[3] = null_node3;
// 	lists[4] = long10;
// 	return lists;
// }
// void	test_ft_lstlast(void)
// {
// 	t_list **lists = lists_tests();
// 	t_list **lists_expected = lists_compare_ft_lstlast();
// 	int i = 0;
// 	int errors = 0;
// 	while (i <= 4)
// 	{
// 		t_list* expected;
// 		t_list*	result;
// 		result = ft_lstlast(lists[i]);
// 		expected = lists_expected[i];
// 		printf(RESET "For %d\n", i);
// 		errors = errors + compare_lists(result, expected);
// 		i++;
// 	}
// 	if (errors == 0)
// 		printf(GREEN "\nft_lstlastOK\n\n"RESET);
// 	else
// 		printf(RED "\nft_lstlastFAIL\n\n" RESET);
// }
// void	test_ft_lstmap(void)
// {
// 	t_list	*list1 = malloc(sizeof(t_list));
// 	t_list	*list2 = malloc(sizeof(t_list));
// 	t_list	*list1_exp = malloc(sizeof(t_list));
// 	t_list	*list2_exp = malloc(sizeof(t_list));
// 	int		errors;
// 	errors = 0;
// 	list2->content = "two"; list2->next = NULL;
// 	list1->content = "one"; list1->next = list2;
// 	list2_exp->content = "uxp"; list2_exp->next = NULL;
// 	list1_exp->content = "pof"; list1_exp->next = list2_exp;
// 	errors = errors + compare_lists_mem(ft_lstmap(list1, f5_test, del_content), list1_exp);
// 	if (errors == 0)
// 		printf(GREEN "\nft_lstmapOK\n\n"RESET);
// 	else
// 		printf(RED "\nft_lstmapFAIL\n\n" RESET);
// }
// void	test_ft_lstnew(void)
// {
// 	int errors = 0;
// 	t_list	*result;
// 	t_list	*expected;
// 	// classic test
// 	result = ft_lstnew("hello");
// 	expected = malloc(sizeof(t_list));
// 	expected->content = "hello";
// 	expected->next = NULL;
// 	errors = errors + compare_lists(result, expected);
// 	free(expected);
// 	//null test
// 	result = ft_lstnew(NULL);
// 	expected = malloc(sizeof(t_list));
// 	expected->content = NULL;
// 	expected->next = NULL;
// 	errors = errors + compare_lists(result, expected);
// 	free(expected);
// 	// empty test
// 	result = ft_lstnew("");
// 	expected = malloc(sizeof(t_list));
// 	expected->content = "";
// 	expected->next = NULL;
// 	errors = errors + compare_lists(result, expected);
// 	free(expected);
// 	// int test test
// 	int *int_test;
// 	int_test= malloc(sizeof(int) * 1);
// 	int_test[0] = 3;
// 	result = ft_lstnew(int_test);
// 	expected = malloc(sizeof(t_list));
// 	expected->content = int_test;
// 	expected->next = NULL;
// 	errors = errors + compare_lists(result, expected);
// 	free(expected);
// 	free(int_test);
// 	if (errors == 0)
// 		printf(GREEN "\nft_lstnewOK\n\n"RESET);
// 	else
// 		printf(RED "\nft_lstnewFAIL\n\n" RESET);
// }
// void	test_ft_lstsize(void)
// {
// 	t_list **lists = lists_tests();
// 	int i = 0;
// 	int errors = 0;
// 	while (i <= 4)
// 	{
// 		int expected;
// 		int	result;
// 		result = ft_lstsize(lists[i]);
// 		if(i == 0)
// 			expected = 3;
// 		if (i == 1)
// 			expected = 1;
// 		if (i == 2)
// 			expected = 0;
// 		if (i == 3)
// 			expected = 3;
// 		if (i == 4)
// 			expected = 10;
// 		if (result == expected)
// 			printf(GREEN "For %d: %d --> %d\n" RESET, i, result, expected);
// 		else
// 		{
// 			printf(RED "For %d: %d --> %d\n" RESET, i, result, expected);
// 			errors++;
// 		}
// 		i++;
// 	}
// 	if (errors == 0)
// 		printf(GREEN "\nft_lstsizeOK\n\n"RESET);
// 	else
// 		printf(RED "\nft_lstsizeFAIL\n\n" RESET);
// }
void	test_ft_memchr(void)
{
	size_t len_charstar;
	size_t i;
	size_t len_int;
	size_t j;
	int errors;
	size_t n;
	char *charstar_test;
	len_charstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	len_int = sizeof(int_tests) / sizeof(int_tests[0]);
	j = 0;
	errors = 0;
	while (i < len_charstar)
	{
		while (j < len_int)
		{
			n = strlen(const_charstar_tests[i]);
			charstar_test = malloc(sizeof(char) * (n + 1));
			strcpy(charstar_test, const_charstar_tests[i]);
			printf(RESET "For %s and %c: ", const_charstar_tests[i], int_tests[j]);
			errors += compare_ptr(ft_memchr(charstar_test, int_tests[j], n),
								  memchr(charstar_test, int_tests[j], n),
								  charstar_test, n);
			j++;
			free(charstar_test);
		}
		j = 0;
		i++;
	}
	if (errors == 0)
		printf(GREEN "\nft_memchr OK\n\n"RESET);
	else
		printf(RED "\nft_memchr FAIL\n\n" RESET);
}
void	test_ft_memcmp(void)
{
	size_t	len_charstar;
	size_t	i, j, n;
	int		errors;
	char	*charstar_test1;
	char	*charstar_test2;
	len_charstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	errors = 0;
	i = 0;
	while (i < len_charstar)
	{
		j = 0;
		while (j < len_charstar)
		{
			size_t max_n = strlen(const_charstar_tests[i]) < strlen(const_charstar_tests[j]) ?
						   strlen(const_charstar_tests[i]) : strlen(const_charstar_tests[j]);
			n = 0;
			while (n <= max_n)
			{
				charstar_test1 = malloc(sizeof(char) * (strlen(const_charstar_tests[i]) + 1));
				strcpy(charstar_test1, const_charstar_tests[i]);
				charstar_test2 = malloc(sizeof(char) * (strlen(const_charstar_tests[j]) + 1));
				strcpy(charstar_test2, const_charstar_tests[j]);
				printf(RESET "\nFor \"%s\" and \"%s\" with n = %zu: ",
					   charstar_test1, charstar_test2, n);
				errors += compare_int(ft_memcmp(charstar_test1, charstar_test2, n),
									  memcmp(charstar_test1, charstar_test2, n));
				free(charstar_test1);
				free(charstar_test2);
				n++;
			}
			j++;
		}
		i++;
	}
	if(errors == 0)
		printf(GREEN "\nft_memcmp OK\n\n"RESET);
	else
		printf(RED "\nft_memcmp FAIL\n\n" RESET);
}
void	test_ft_memcpy(void)
{
	size_t  len_charstar;
	size_t  i;
	size_t  len_size;
	size_t  j;
	int     errors;
	size_t  n;
	char    *ft_dest;
	char    *libc_dest;
	len_charstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	len_size = sizeof(size_t_tests) / sizeof(size_t_tests[0]);
	j = 0;
	errors = 0;
	while (i < len_charstar)
	{
		while (j < len_size)
		{
			n = size_t_tests[j];
			ft_dest = malloc(strlen(const_charstar_tests[i]) + n + 1);
			libc_dest = malloc(strlen(const_charstar_tests[i]) + n + 1);
			strcpy(ft_dest, const_charstar_tests[i]);
			strcpy(libc_dest, const_charstar_tests[i]);
			printf(RESET "\nFor %s and n=%zu: ", const_charstar_tests[i], n);
			errors = errors + compare_mem(ft_memcpy(ft_dest, const_charstar_tests[i], n),
										 memcpy(libc_dest, const_charstar_tests[i], n),
										 n);
			free(ft_dest);
			free(libc_dest);
			j++;
		}
		j = 0;
		i++;
	}
	if(errors == 0)
		printf(GREEN "\nft_memcpy OK\n\n"RESET);
	else
		printf(RED "\nft_memcpy FAIL\n\n" RESET);
}
void	test_ft_memmove(void)
{
	size_t	len_charstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	size_t	i = 0, j;
	int		errors = 0;
	size_t	n, move_len;
	char	*charstar_test_ft;
	char	*charstar_test_man;
	while (i < len_charstar)
	{
		n = strlen(const_charstar_tests[i]);
		j = 0;
		while (j <= n)
		{
			move_len = n - j;
			if (move_len > 0)
			{
				charstar_test_ft = malloc(sizeof(char) * (n + 1));
				strcpy(charstar_test_ft, const_charstar_tests[i]);
				charstar_test_man = malloc(sizeof(char) * (n + 1));
				strcpy(charstar_test_man, const_charstar_tests[i]);
				printf(RESET "For %s with offset %zu: ", const_charstar_tests[i], j);
				errors += compare_mem(
					ft_memmove(charstar_test_ft, charstar_test_ft + j, move_len),
					memmove(charstar_test_man, charstar_test_man + j, move_len),
					move_len
				);
				free(charstar_test_ft);
				free(charstar_test_man);
			}
			j++;
		}
		i++;
	}
	if (errors == 0)
		printf(GREEN "\nft_memmove OK\n\n"RESET);
	else
		printf(RED "\nft_memmove FAIL\n\n" RESET);
}
void	test_ft_memset(void)
{
	size_t	len_charstar;
	size_t	i;
	size_t	len_int;
	size_t	j;
	int		errors;
	size_t	n;
	char	*charstar_test_ft;
	char	*charstar_test_man;
	len_charstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	len_int = sizeof(int_tests) / sizeof(int_tests[0]);
	j = 0;
	errors = 0;
	while (i < len_charstar)
	{
		while (j < len_int)
		{
			n = strlen(const_charstar_tests[i]);
			charstar_test_ft = malloc(sizeof(char) * (n + 1));
			strcpy(charstar_test_ft, const_charstar_tests[i]);
			charstar_test_man = malloc(sizeof(char) * (n + 1));
			strcpy(charstar_test_man, const_charstar_tests[i]);
			printf(RESET "For %s and %c: ", charstar_tests[i], int_tests[j]);
			errors = errors + compare_mem(ft_memset((void *)charstar_test_ft, int_tests[j], n), memset((void *)charstar_test_man, int_tests[j], n), n);
			j++;
			free(charstar_test_ft);
			free(charstar_test_man);
		}
		j = 0;
		i++;
	}
	if(errors == 0)
		printf(GREEN "\nft_memset OK\n\n"RESET);
	else
		printf(RED "\nft_memset FAIL\n\n" RESET);
}
void	test_ft_putchar_fd(void)
{
	printf(YELLOW"\n");
	ft_putchar_fd('a', 0);
	ft_putchar_fd('b', 1);
	ft_putchar_fd('c', 2);
	printf(YELLOW "\nft_putchar_fd has to be checked visually\n\n" RESET);
}
void	test_ft_putendl_fd(void)
{
	ft_putendl_fd("abc", 0);
	ft_putendl_fd("", 0);
	ft_putendl_fd("\n", 0);
	ft_putendl_fd("123", 1);
	ft_putendl_fd("def", 2);
	printf(YELLOW "\nft_putendl_fd has to be checked visually\n\n" RESET);
}
void	test_ft_putnbr_fd(void)
{
	ft_putnbr_fd(123, 1);
	printf(YELLOW " --> \"%s\"\n", "123");
	ft_putnbr_fd(0, 1);
	printf(" --> \"%s\"\n", "0");
	ft_putnbr_fd(-2147483648, 1);
	printf(" --> \"%s\"\n", "-2147483648");
	ft_putnbr_fd(2147483647, 1);
	printf(" --> \"%s\"\n", "2147483647");
	ft_putnbr_fd(-123, 1);
	printf(" --> \"%s\"\n", "-123");
	printf("\ncheck the fd:\n");
	ft_putnbr_fd(123, 0);
	printf(" --> \"%s\"\n", "123");
	ft_putnbr_fd(123, 2);
	printf(" --> \"%s\"\n", "123");
	printf(YELLOW "\nft_putnbr_fd has to be checked visually\n\n" RESET);
}
void	test_ft_putstr_fd(void)
{
	ft_putstr_fd("abc", 0);
	ft_putstr_fd("", 0);
	ft_putstr_fd("\n", 0);
	ft_putstr_fd("123", 1);
	ft_putstr_fd("def", 2);
	printf(YELLOW "\nft_putstr_fd has to be checked visually\n\n");
}
void	free_split(char **tab)
{
	size_t i = 0;
	if (!tab) return;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
void	test_ft_split(void)
{
	char **res;
	char *s;
	char **expected;
	int errors = 0;

	// Test classic
	s = "hello world test";
	expected = malloc(sizeof(char *) * 4);
	expected[0] = strdup("hello");
	expected[1] = strdup("world");
	expected[2] = strdup("test");
	expected[3] = NULL;
	res = ft_split(s, ' ');
	if (compare_charstarstar(res, expected) == 0)
		printf(RESET "For: %s" GREEN " OK\n", s);
	else
	{
		printf(RESET "For: %s" RED "FAIL\n", s);
		errors++;
	}
	free_split(res);
	free_split(expected);

	// Test with empty lines
	s = "   a  b c   ";
	expected = malloc(sizeof(char *) * 4);
	expected[0] = strdup("a");
	expected[1] = strdup("b");
	expected[2] = strdup("c");
	expected[3] = NULL;
	res = ft_split(s, ' ');
	if (compare_charstarstar(res, expected) == 0)
		printf(RESET "For: %s" GREEN " OK\n", s);
	else
	{
		printf(RESET "For: %s" RED "FAIL\n", s);
		errors++;
	}
	free_split(res);
	free_split(expected);

	if (errors == 0)
		printf(GREEN "ft_split : all tests passed\n");
	else
		printf(RED "ft_split : test(s) failed\n");
}
void	test_ft_strchr(void)
{
	size_t  len_int;
	size_t  len_constcharstar;
	size_t i;
	size_t  j;
	int errors;
	len_int = sizeof(int_tests) / sizeof(int_tests[0]);
	len_constcharstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	j = 0;
	errors = 0;
	while(i < len_int)
	{
		while(j < len_constcharstar)
		{
			printf(RESET "For \"%s\" and %d: ", const_charstar_tests[j], int_tests[i]);
			errors = errors + compare_charstar(ft_strchr(const_charstar_tests[j], int_tests[i]),
				strchr(const_charstar_tests[j], int_tests[i]));
			j++;
		}
		j = 0;
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_strchr OK\n\n"RESET);
	else
		printf(RED "ft_strchr FAIL\n\n" RESET);
}
void	test_ft_strdup(void)
{
	size_t  len_constcharstar;
	size_t i;
	int errors;
	len_constcharstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	errors = 0;
	while(i < len_constcharstar)
	{
		printf(RESET "For \"%s\": ", const_charstar_tests[i]);
		errors = errors + compare_charstar(ft_strdup(const_charstar_tests[i]), strdup(const_charstar_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_strdup OK\n\n"RESET);
	else
		printf(RED "ft_strdup FAIL\n\n" RESET);
}
int		sub_test_ft_striteri(char *s, void (*f)(unsigned int, char*), char* name_function, char* expected)
{
	char*  result;
	printf(RESET "For \"%s\"and \"%s\": ", s, name_function);
	ft_striteri(s, f);
	result = s;
	if (strcmp(result, expected) == 0)
	{
		printf(GREEN "\"%s\" --> \"%s\"\n", result, expected);
		return(0);
	}
	else
	{
		printf(RED "\"%s\" --> \"%s\"\n", result, expected);
		return(1);
	}
}
void	test_ft_striteri(void)
{
	int errors;
	char* s;
	char* name_function;
	char* expected;
	errors = 0;
	// f3 change caracteres by a execpt the first //
	s = malloc(4);
	ft_strlcpy(s, "123", 4);
	name_function = "f3_test";
	expected = "12a";
	errors = errors + sub_test_ft_striteri(s, f3_test, name_function, expected);
	// f3 change caracteres by a execpt the first //
	s = malloc(1);
	ft_strlcpy(s, "", 1);
	name_function = "f3_test";
	expected = "";
	errors = errors + sub_test_ft_striteri(s, f3_test, name_function, expected);
	if(errors == 0)
		printf(GREEN "ft_striteri OK\n\n"RESET);
	else
		printf(RED "ft_striteri FAIL\n\n" RESET);
}
int		sub_test_ft_strjoin(char const* s1, char const* s2, char* expected)
{
	char*  result;
	printf(RESET "For \"%s\"and \"%s\": ", s1, s2);
	result = ft_strjoin(s1, s2);
	if (strcmp(result, expected) == 0)
	{
		printf(GREEN "\"%s\" --> \"%s\"\n", result, expected);
		return(0);
	}
	else
	{
		printf(RED "\"%s\" --> \"%s\"\n", result, expected);
		return(1);
	}
}
void	test_ft_strjoin(void)
{
	int         errors;
	char const* s1;
	char const* s2;
	char*       expected;
	errors = 0;
	// s1 empty //
	s1 = "";
	s2 = " ca va ?";
	expected = " ca va ?";
	errors = errors + sub_test_ft_strjoin(s1, s2, expected);
	// s2 empty //
	s1 = "salut";
	s2 = "";
	expected = "salut";
	errors = errors + sub_test_ft_strjoin(s1, s2, expected);
	// s1 and s2 empty //
	s1 = "";
	s2 = "";
	expected = "";
	errors = errors + sub_test_ft_strjoin(s1, s2, expected);
	// classic //
	s1 = "salut";
	s2 = " ca va ?";
	expected = "salut ca va ?";
	errors = errors + sub_test_ft_strjoin(s1, s2, expected);
	if (errors == 0)
		printf(GREEN "ft_strjoin OK\n\n"RESET);
	else
		printf(RED "ft_strjoin FAIL\n\n" RESET);
}
/*
int		sub_test_ft_strlcat(char* destman, char* destft, const char* src, size_t dsize)
{
	size_t  result;
	size_t expected;
	printf(RESET "For \"%s\", \"%s\", %zu: ", destman, src, dsize);
	result = ft_strlcat(destft, src, dsize);
	expected = strlcat(destman, src, dsize);
	if (result == expected && strcmp(destft, destman) == 0)
	{
		printf(GREEN "%zu --> %zu and \"%s\" --> \"%s\"\n", result, expected, destft, destman);
		return(0);
	}
	else
	{
		printf(RED "%zu --> %zu and \"%s\" --> \"%s\"\n", result, expected, destft, destman);
		return(1);
	}
}
void	test_ft_strlcat(void)
{
	int errors;
	char* destman;
	char* destft;
	const char* src;
	size_t  dsize;
	errors = 0;
	// dsize equal to src and dest not empty//
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	strlcpy(destman, "12", 3);
	strlcpy(destft, "12", 3);
	src = "abc";
	dsize = 4;
	errors = errors + sub_test_ft_strlcat(destman, destft, src, dsize);
	// dsize lower than src //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "abc";
	dsize = 3;
	errors = errors + sub_test_ft_strlcat(destman, destft, src, dsize);
	// dsize higher than src //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "a";
	dsize = 2;
	errors = errors + sub_test_ft_strlcat(destman, destft, src, dsize);
	// test dsize null //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "a";
	dsize = 0;
	errors = errors + sub_test_ft_strlcat(destman, destft, src, dsize);
	// test src empty //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "";
	dsize = 3;
	errors = errors + sub_test_ft_strlcat(destman, destft, src, dsize);
	if(errors == 0)
		printf(GREEN "ft_strlcat OK\n\n"RESET);
	else
		printf(RED "ft_strlcat FAIL\n\n" RESET);
}
int		sub_test_ft_strlcpy(char* destman, char* destft, const char* src, size_t dsize)
{
	size_t  result;
	size_t expected;
	printf(RESET "For \"%s\", \"%s\", %zu: ", destman, src, dsize);
	result = ft_strlcpy(destft, src, dsize);
	expected = strlcpy(destman, src, dsize);
	if (result == expected && strcmp(destft, destman) == 0)
	{
		printf(GREEN "%zu --> %zu and \"%s\" --> \"%s\"\n", result, expected, destft, destman);
		return(0);
	}
	else
	{
		printf(RED "%zu --> %zu and \"%s\" --> \"%s\"\n", result, expected, destft, destman);
		return(1);
	}
}
void	test_ft_strlcpy(void)
{
	int errors;
	char* destman;
	char* destft;
	const char* src;
	size_t  dsize;
	errors = 0;
	// dsize equal to src //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "abc";
	dsize = 4;
	errors = errors + sub_test_ft_strlcpy(destman, destft, src, dsize);
	// dsize lower than src //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "abc";
	dsize = 3;
	errors = errors + sub_test_ft_strlcpy(destman, destft, src, dsize);
	// dsize higher than src //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "a";
	dsize = 2;
	errors = errors + sub_test_ft_strlcpy(destman, destft, src, dsize);
	// test dsize null //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "a";
	dsize = 0;
	errors = errors + sub_test_ft_strlcpy(destman, destft, src, dsize);
	// test src empty //
	destman = malloc(sizeof(char)*(3 + 1));
	destft = malloc(sizeof(char)*(3 + 1));
	src = "";
	dsize = 3;
	errors = errors + sub_test_ft_strlcpy(destman, destft, src, dsize);
	if(errors == 0)
		printf(GREEN "ft_strlcpy OK\n\n"RESET);
	else
		printf(RED "ft_strlcpy FAIL\n\n" RESET);
}
*/
void	test_ft_strlen(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For \"%s\": ", const_charstar_tests[i]);
		errors = errors + compare_sizet(ft_strlen(const_charstar_tests[i]), strlen(const_charstar_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_strlen OK\n\n"RESET);
	else
		printf(RED "ft_strlen FAIL\n\n" RESET);
}
int		sub_test_ft_strmapi(char const *s, char (*f)(unsigned int, char), char* name_function, char* expected)
{
	char*  result;
	printf(RESET "For \"%s\"and \"%s\": ", s, name_function);
	result = ft_strmapi(s, f);
	if (strcmp(result, expected) == 0)
	{
		printf(GREEN "\"%s\" --> \"%s\"\n", result, expected);
		return(0);
	}
	else
	{
		printf(RED "\"%s\" --> \"%s\"\n", result, expected);
		return(1);
	}
}
void	test_ft_strmapi(void)
{
	int errors;
	char* s;
	char* name_function;
	char* expected;
	errors = 0;
	// f1 change caracteres by a execpt the first //
	s = "123";
	name_function = "f1_test";
	expected = "1aa";
	errors = errors + sub_test_ft_strmapi(s, f1_test, name_function, expected);
	// f1 caracteres by one execpt the first //
	s = "";
	name_function = "f1_test";
	expected = "";
	errors = errors + sub_test_ft_strmapi(s, f1_test, name_function, expected);
	// f2 change caractere 0 by caractere 9 if i < 10000 //
	s = "019";
	name_function = "f2_test";
	expected = "919";
	errors = errors + sub_test_ft_strmapi(s, f2_test, name_function, expected);
	if(errors == 0)
		printf(GREEN "ft_strmapi OK\n\n"RESET);
	else
		printf(RED "ft_strmapi FAIL\n\n" RESET);
}
void	test_ft_strncmp(void)
{
	size_t  len_const_charstar;
	size_t  len_sizet;
	size_t i;
	size_t  j;
	size_t k;
	int errors;
	len_const_charstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	len_sizet = sizeof(size_t_tests) / sizeof(size_t_tests[0]);
	i = 0;
	j = 0;
	k= 0;
	errors = 0;
	while(i < len_const_charstar)
	{
		while(j < len_const_charstar)
		{
			while(k < len_sizet)
			{
				printf(RESET "For \"%s\", \"%s\" and %zu: ", const_charstar_tests[i], const_charstar_tests[j], size_t_tests[k]);
				errors = errors + compare_int(ft_strncmp(const_charstar_tests[i], const_charstar_tests[j], size_t_tests[k]),
					strncmp(const_charstar_tests[i], const_charstar_tests[j], size_t_tests[k]));
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_strncmp OK\n\n"RESET);
	else
		printf(RED "ft_strncmp FAIL\n\n" RESET);
}
/*
void test_ft_strnstr(void)
{
	size_t  len_const_charstar;
	size_t  len_sizet;
	size_t i;
	size_t j;
	size_t k;
	int errors;
	len_const_charstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	len_sizet = sizeof(size_t_tests) / sizeof(size_t_tests[0]);
	i = 0;
	j = 0;
	k= 0;
	errors = 0;
	while(i < len_const_charstar)
	{
		while(j < len_const_charstar)
		{
			while(k < len_sizet)
			{
				printf(RESET "For \"%s\", \"%s\" and %zu: ", const_charstar_tests[i], const_charstar_tests[j], size_t_tests[k]);
				errors = errors + compare_charstar(ft_strnstr(const_charstar_tests[i], const_charstar_tests[j], size_t_tests[k]),
					strnstr(const_charstar_tests[i], const_charstar_tests[j], size_t_tests[k]));
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_strnstr OK\n\n"RESET);
	else
		printf(RED "ft_strnstr FAIL\n\n" RESET);
}
*/
void	test_ft_strrchr(void)
{
	size_t  len_int;
	size_t  len_constcharstar;
	size_t i;
	size_t  j;
	int errors;
	len_int = sizeof(int_tests) / sizeof(int_tests[0]);
	len_constcharstar = sizeof(const_charstar_tests) / sizeof(const_charstar_tests[0]);
	i = 0;
	j = 0;
	errors = 0;
	while(i < len_int)
	{
		while(j < len_constcharstar)
		{
			printf(RESET "For \"%s\" and %d: ", const_charstar_tests[j], int_tests[i]);
			errors = errors + compare_charstar(ft_strrchr(const_charstar_tests[j], int_tests[i]),
				strrchr(const_charstar_tests[j], int_tests[i]));
			j++;
		}
		j = 0;
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_strrchr OK\n\n"RESET);
	else
		printf(RED "ft_strrchr FAIL\n\n" RESET);
}
int		sub_test_ft_strtrim(char const* s1, char* set, char* expected)
{
	char*  result;
	printf(RESET "For \"%s\"and \"%s\": ", s1, set);
	result = ft_strtrim(s1, set);
	if (strcmp(result, expected) == 0)
	{
		printf(GREEN "\"%s\" --> \"%s\"\n", result, expected);
		return(0);
	}
	else
	{
		printf(RED "\"%s\" --> \"%s\"\n", result, expected);
		return(1);
	}
}
void	test_ft_strtrim(void)
{
	int errors;
	char const  *s1;
	char    *set;
	char    *expected;
	errors = 0;
	// classic test //
	s1 = "coucou";
	set = "c";
	expected = "oucou";
	errors = errors + sub_test_ft_strtrim(s1, set, expected);
	// s1 empty //
	s1 = "";
	set = "o";
	expected = "";
	errors = errors + sub_test_ft_strtrim(s1, set, expected);
	// set empty //
	s1 = "ciao";
	set = "";
	expected = "ciao";
	errors = errors + sub_test_ft_strtrim(s1, set, expected);
	// s1 and set empty //
	s1 = "";
	set = "";
	expected = "";
	errors = errors + sub_test_ft_strtrim(s1, set, expected);
	// not set in s1/
	s1 = "ciao";
	set = "e";
	expected = "ciao";
	errors = errors + sub_test_ft_strtrim(s1, set, expected);
	// in s1 but not at the beginning or end //
	s1 = "ciao come stai ?";
	set = "i";
	expected = "ciao come stai ?";
	errors = errors + sub_test_ft_strtrim(s1, set, expected);
	// at beginning and end
	s1 = "ciao come staic";
	set = "ciao";
	expected = " come st";
	errors = errors + sub_test_ft_strtrim(s1, set, expected);
	// at beginning and end and repetition
	s1 = "ciao come staic";
	set = "cai";
	expected = " come st";
	errors = errors + sub_test_ft_strtrim(s1, set, expected);
	if(errors == 0)
		printf(GREEN "ft_strtrim OK\n\n"RESET);
	else
		printf(RED "ft_strtrim FAIL\n\n" RESET);
}
void	test_ft_tolower(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(int_tests) / sizeof(int_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For %d: ", int_tests[i]);
		errors = errors + compare_int(ft_tolower(int_tests[i]), tolower(int_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_tolower OK\n\n"RESET);
	else
		printf(RED "ft_tolower FAIL\n\n" RESET);
}
void	test_ft_toupper(void)
{
	size_t  len;
	size_t i;
	int errors;
	len = sizeof(int_tests) / sizeof(int_tests[0]);
	i = 0;
	errors = 0;
	while(i < len)
	{
		printf(RESET "For %d: ", int_tests[i]);
		errors = errors + compare_int(ft_toupper(int_tests[i]), toupper(int_tests[i]));
		i++;
	}
	if(errors == 0)
		printf(GREEN "ft_toupper OK\n\n"RESET);
	else
		printf(RED "ft_toupper FAIL\n\n" RESET);
}
void	run_tests(void)
{
	//test_ft_atoi();
	//test_ft_bzero();
	//test_ft_calloc();
	//test_ft_isalnum();
	// test_ft_isalpha();
	// test_ft_isascii();
	// test_ft_isdigit();
	// test_ft_isprint();
	 //test_ft_itoa();
	 //test_ft_lstadd_back();
	 //test_ft_lstadd_front();
	 //test_ft_lstclear();
	 //test_ft_lstdelone();
	 //test_ft_lstiteri();
	 //test_ft_lstlast();
	 //test_ft_lstmap();
	 //test_ft_lstnew();
	 //test_ft_lstsize();
	 //test_ft_memchr();
	 //test_ft_memcmp();
	 //test_ft_memcpy();
	 //test_ft_memset();
	 //test_ft_memmove();
	 //test_ft_putchar_fd();
	 //test_ft_putendl_fd();
	 //test_ft_putnbr_fd();
	 //test_ft_putstr_fd();
	 //test_ft_split();
	 //test_ft_strchr();
	 //test_ft_strdup();
	 //test_ft_striteri();
	 //test_ft_strjoin();
	//test_ft_strlcat();
	//test_ft_strlcpy();
	 //test_ft_strlen();
	 //test_ft_strmapi();
	 //test_ft_strncmp();
	test_ft_strrchr();
	//  test_ft_strtrim();
	//  test_ft_tolower();
	//  test_ft_toupper();
}
