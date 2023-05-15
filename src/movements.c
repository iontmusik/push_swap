/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:29:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/15 12:40:06 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_swap(t_stack **stack, char c, t_push *push)
{
	int			num1;
	int			num2;
	int			pos_temp;
	t_stack		*temp;

	if (stack)
	{
		temp = *stack;
		num1 = (*stack)->content;
		num2 = (*stack)->next->content;
		pos_temp = (*stack)->pos;
		temp->content = num2;
		temp->pos = (*stack)->next->pos;
		temp->next = (*stack)->next;
		temp->next->pos = pos_temp;
        temp->next->content = num1;
		temp->next->next = (*stack)->next->next;
		*stack = temp;
		if (c == 'a' || c == 'b')
			print_and_moves_s(push, c);
	}
}

void	ss_swap(t_stack *a, t_stack *b, t_push *push)
{
	s_swap(&a, 's', push);
	s_swap(&b, 's', push);
	printf("ss");
	push->moves++;
}

void	p_swap(t_stack **stack1, t_stack **stack2, char c, t_push *push)
{
	t_stack	*temp;

	if (stack2)
	{
		temp = (*stack2);
		(*stack2) = (*stack2)->next;
		temp->next = *stack1;
		temp->pos = (*stack1)->pos;
		*stack1 = temp;
		print_and_moves_p(push, c);
	}
	return ;
}

void	r_swap(t_stack **stack, char c, t_push *push)
{
	int		num;
    t_stack	*temp;

	temp = NULL;
	if (stack)
	{
		num = (*stack)->content;
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (temp == NULL)
			exit (1);
		temp->content = num;
		temp->next = (*stack)->next;
		temp->pos = (*stack)->pos;
		(*stack) = (*stack)->next;
		ft_lstadd_back_ps(stack, temp);
		if (c == 'a' || c == 'b')
			print_and_moves_r(push, c);
	}
}

void	rr_swap(t_stack **stack1, t_stack **stack2, t_push *push)
{
	r_swap(stack1, 'r', push);
	r_swap(stack2, 'r', push);
	printf("rr\n\n");
	push->moves++;
}

void	r_rev_swap(t_stack **stack, char c, t_push *push)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	if (before_last)
		before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c == 'a' || c == 'b')
		print_and_moves_w(push, c);
}


/* 
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
    printf("%d\n", b->content);
    printf("%d\n", b->next->content);
    printf("%d\n\n", b->next->next->content); 
    //rr_swap(&a, &b, 's', &push);
    r_rev_swap(&a, 'a', &push);
    printf("%d\n", a->content);
    printf("%d\n", a->next->content);
    printf("%d\n\n", a->next->next->content);
     printf("%d\n", b->content);
    printf("%d\n", b->next->content);
    printf("%d\n\n", b->next->next->content); 
    return (0);
} 
 */