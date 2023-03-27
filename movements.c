/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:29:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/03/27 18:15:52 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int             content;
    struct s_stack  *next;
}   t_stack;

typedef struct s_push
{
    t_stack *a;
    t_stack *b;
    char    **split;
    char    *fd;
    int     len;
    int     len_a;
    int     len_b;
    int     moves;
}   t_push;

void ft_init_push(t_push *push)
{
    push = (t_push *)malloc(sizeof(t_push));
    if (push == NULL)
        exit(1);
    push->a = NULL;
    push->b = NULL;
    push->split = NULL;
    push->moves = 0;
    push->len = 0;
    push->len_a = 0;
    push->len_b = 0;
    return ;
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	*ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*ultimo;

	if (lst == NULL)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ultimo = ft_lstlast_ps(*lst);
		if (ultimo)
			ultimo->next = new;
	}
}


void    s_swap(t_stack *stack, char c, t_push *push)
{
    int num1;
    int num2;
    t_stack *temp;
    
    if (stack && stack->next)
    {
        temp = stack;
        num1 = stack->content;
        num2 = stack->next->content;
        temp->content = num2;
        temp->next->content = num1;
        stack = temp;

        if (c == 'a')
            printf("sa\n");
            
        else if (c == 'b')
            printf("sb\n");
        push->moves++;
    }
    return ;
}
void    ss_swap(t_stack *a, t_stack *b, char c, t_push *push)
{
    s_swap(a, 's',  push);
    s_swap(b, 's', push);
    printf("ss");
    return ;
}

void    p_swap(t_stack **stack1, t_stack **stack2, char c, t_push *push)
{
    int     num;
    t_stack *temp;
    
    if (stack2)
    {
        temp = (*stack2);
        (*stack2) = (*stack2)->next;
        temp->next = *stack1;
        *stack1 = temp;
        if (c == 'a')
        {
            push->len_a -= 1;
            push->len_b += 1;
            printf("pa\n");
        }
        else if (c == 'b')
        {
            push->len_a += 1;
            push->len_b -= 1;
            printf("pb\n");
        }
    push->moves++;
    }
    return ;
}

void    r_swap(t_stack **stack, char c, t_push *push)
{
    int     num;
    t_stack *temp;

    temp = NULL;
    if (stack)
    {
        num = (*stack)->content;
        temp = (t_stack *)malloc(sizeof(t_stack));
        if (temp == NULL)
            exit (1);
        temp->content = num;
        temp->next = NULL;
        (*stack) = (*stack)->next;
        ft_lstadd_back_ps(stack, temp);
        if (c == 'a')
            printf("ra\n");
        else if (c == 'b')
            printf("rb\n");
        push->moves++;
    }
    return ;
}

void    rr_swap(t_stack **stack1, t_stack **stack2, char c, t_push *push)
{
    r_swap(stack1, 'r', push);
    r_swap(stack2, 'r', push);
    printf("rr\n\n");
}

void	ft_lstiter_ps(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
}

void    r_rev_swap(t_stack **stack, char c, t_push *push)
{
    t_stack *temp;
    t_stack *temp2;

    temp = NULL;
    if (stack)
    {
        temp = ft_lstlast_ps(*stack);
        ft_lstadd_back_ps(*stack, temp);
        ft_lstiter_ps(temp2);
        temp2->next = NULL;
        temp->next = *stack;
        *stack = temp;
        if (c == 'a')
            printf("rra\n");
        else if (c == 'b')
            printf("rrb\n");
        push->moves++;
    }
    return ;
}

void    rr_rev_swap(t_stack **stack1, t_stack **stack2, char c, t_push *push)
{
    r_rev_swap(stack1, 'r', push);
    r_rev_swap(stack2, 'r', push);
    printf("rrr\n\n");
}

int main()
{
    t_push push;
    ft_init_push(&push);
    t_stack *a = malloc(sizeof(t_stack));
    t_stack *b = malloc(sizeof(t_stack));
    
    a->content = 5;
    a->next = malloc(sizeof(t_stack));
    a->next->content = 3;
    a->next->next = malloc(sizeof(t_stack));
    a->next->next->content = 7;
    a->next->next = malloc(sizeof(t_stack));
    a->next->next->next->content = 43;
    b->content = 8;
    b->next = malloc(sizeof(t_stack));
    b->next->content = 9;
    b->next->next = malloc(sizeof(t_stack));
    b->next->next->content = 56;
    
    printf("%d\n", a->content);
    printf("%d\n", a->next->content);
    printf("%d\n\n", a->next->next->content);
/*     printf("%d\n", b->content);
    printf("%d\n", b->next->content);
    printf("%d\n\n", b->next->next->content); */
    //rr_swap(&a, &b, 's', &push);
    r_rev_swap(&a, 'a', &push);
    printf("%d\n", a->content);
    printf("%d\n", a->next->content);
    printf("%d\n\n", a->next->next->content);
/*     printf("%d\n", b->content);
    printf("%d\n", b->next->content);
    printf("%d\n\n", b->next->next->content); */
    return (0);
}
