#include "../include/push_swap.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include "printf.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				pos;
}	t_stack;

typedef struct s_push
{
	t_stack	*a;
	t_stack	*b;
	char	**split;
	int		len_a;
	int		len_b;
	int		posmax_a;
	int		posmin_a;
	int		posmax_b;
	int		posmin_b;
	int		max_a;
	int		max_b;
	int		min_a;
	int		min_b;
	int		moves;
	int		cont_new;
}	t_push;

// INIT STRUCT  ARCHIVE: init.c
t_push		*ft_init_push(t_push *push);
void		put_arg_to_int(t_stack **stack, char **av, t_push *push);
t_stack		*ft_lstnew_ps(int content);
void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_order_lst(t_stack *a, t_stack *new);
void		position_nums(t_stack *stack, t_stack *new);

// UTILS  ARCHIVE: push_swap_utils.c
t_stack		*ft_lstlast_ps(t_stack *lst);
void		ft_lstiter_ps(t_stack *lst);

// PRINT MOVEMENTS  ARCHIVE: print_moves.c
void		print_and_moves_s(t_push *push, char c);
void		print_and_moves_p(t_push *push, char c);
void		print_and_moves_r(t_push *push, char c);
void		print_and_moves_w(t_push *push, char c);

// MAX NUM & MIN NUM & COUNT NUMS ARCHIVE count_max_min.c
void		maxminstack(t_stack *stack, t_push *push, char c);
int			count_nums(t_stack *stack);
void		ft_maximo(t_stack *stack, t_push *push, char c);
void		ft_minimo(t_stack *stack, t_push *push, char c);
void		pos_num_min(t_stack *stack, t_push *push, char c);
void		pos_num_max(t_stack *stack, t_push *push, char c);
void		posmaxmin(t_stack *stack, t_push *push, char c);

// POS MAX NUM & POS MIN NUM   ARCHIVE: pos_max_min.c
void		posmaxmin(t_stack *stack, t_push *push, char c);

// CHECKING NUMS  ARCHIVE: checking.c
int			duplicate_nums(char **split);
int			int_limits(char *av);
long long	atoi_ps(char *num_char);
int			is_nums(char **av);

// EXIT ARCHIVE: exit.c
int			exit_ps(char *text);

// MOVEMENTS  ARCHIVE: movements.c movements2.c
// SWAP: SA, SB, SS
void		s_swap(t_stack **stack, char c, t_push *push);
void		ss_swap(t_stack *a, t_stack *b, t_push *push);
// PUSH: PA, PB
void		p_swap(t_stack **stack1, t_stack **stack2, char c, t_push *push);
// ROTATE: RA, RB, RR
void		r_swap(t_stack **stack, char c, t_push *push);
void		rr_swap(t_stack **stack1, t_stack **stack2, t_push *push);
void		ra_rra(t_stack **stack_a, t_push *push, int pos);
// ROTATE REVERSE: RRA, RRB, RRR
void		r_rev_swap(t_stack **stack, char c, t_push *push);
void		rr_rev_swap(t_stack **stack1, t_stack **stack2, t_push *push);

// ALGORITHMS
void		algo_2(t_stack **stack, t_push *push);
void		algo_3(t_stack **stack1, t_push *push);
void		algo_5(t_stack **stack_a, t_stack **stack_b, t_push *push);
void		ft_move_a(t_stack **stack_a, t_stack **stack_b, t_push *push);
void		select_algo(t_stack **stack_a, t_stack **stack_b, t_push *push);


#endif



void	select_algo(t_stack **stack_a, t_stack **stack_b, t_push *push)
{
	push->len_a = count_nums(*stack_a);
	push->len_b = count_nums(*stack_b);
	maxminstack(*stack_a, push, 'a');
	posmaxmin(*stack_a, push, 'a');
	if (push->len_a <= 2)
		algo_2(stack_a, push);
	else if (push->len_a <= 3)
	{
		algo_3(stack_a, push);
	}
	else if (push->len_a <= 5)
		algo_5(stack_a, stack_b, push);
}


void	algo_2(t_stack **stack, t_push *push)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->content > tmp->next->content)
		s_swap(stack, 'a', push);
}

void	algo_3(t_stack **stack1, t_push *push)
{
	int			num1;
	int			num2;
	int			num3;
	t_stack		*tmp;

	num1 = 0;
	num2 = 0;
	num3 = 0;
	while (!(num1 < num2 && num2 < num3 && num1 < num3))
	{
		tmp = (*stack1);
		num1 = tmp->content;
		tmp = tmp->next;
		num2 = tmp->content;
		tmp = tmp->next;
		num3 = tmp->content;
		if ((num1 > num2 && num1 < num3 && num2 < num3) 
			|| (num1 > num3 && num2 > num3 && num1 > num2)
			|| (num1 < num2 && num1 < num3 && num2 > num3))
			s_swap(stack1, 'a', push);
		else if (num1 > num2 && num1 > num3 && num2 < num3)
			r_swap(stack1, 'a', push);
		else if (num1 < num2 && num1 > num3 && num2 > num3)
			r_rev_swap(stack1, 'a', push);
		else
			break;
	}
}

void	algo_5(t_stack **stack_a, t_stack **stack_b, t_push *push)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (push->len_b < 2)
	{
		tmp = *stack_a;
		printf("Primero numero  de stack A es: %d\n", (*stack_a)->content);
		posmaxmin(*stack_a, push, 'a');
		printf("Numero minimo: %d\n", push->min_a);
		if (tmp->content == push->max_a || tmp->content == push->min_a)
		{
			p_swap(stack_a, stack_b, 'b', push);
		}
		else if (push->len_b == 1)
		{
			ra_rra(stack_a, push, push->max_a);
		}
		else
		{
			ra_rra(stack_a, push, push->min_a);
		}
	}
	select_algo(stack_a, stack_b, push);
	while (push->len_b != 0)
	{
		ft_move_a(stack_a, stack_b, push);
	}
}

void	ft_move_a(t_stack **stack_a, t_stack **stack_b, t_push *push)
{
	int		a;
	t_stack	*tmp;

	tmp = *stack_a;
	a = tmp->content;
	tmp = *stack_b;
	p_swap(stack_a, stack_b, 'a', push);
	if (tmp->content > a)
		r_swap(stack_a, 'a', push);
	return ;
}

#include "../include/push_swap.h"

void	ft_minimo(t_stack *stack, t_push *push, char c)
{
	push->min_a = 2147483647;
	push->min_b = 2147483647;
	if (c == 'a')
	{
		while (stack != NULL)
		{
			if (stack->content < push->min_a)
				push->min_a = stack->content;
			stack = stack->next;
		}
	}
	if (c == 'b')
	{
		while (stack != NULL)
		{
			if (stack->content < push->min_b)
				push->min_b = stack->content;
			stack = stack->next;
		}
	}
}



 void	ft_maximo(t_stack *stack, t_push *push, char c)
{
	push->max_a = -2147483648;
	push->max_b = -2147483648;
	if (c == 'a')
	{
		while (stack != NULL)
		{
			if (stack->content > push->max_a)
				push->max_a = stack->content;
			stack = stack->next;
		}
	}
	if (c == 'b')
	{
		while (stack != NULL)
		{
			if (stack->content < push->max_b)
				push->max_b = stack->content;
			stack = stack->next;
		}
	}
}

void	maxminstack(t_stack *stack, t_push *push, char c)
{
	ft_minimo(stack, push, c);
	ft_maximo(stack, push, c);
}

int	count_nums(t_stack *stack)
{	
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	position_nums(t_stack *stack, t_stack *new)
{
	while (stack)
	{
		if (new->content > stack->content)
			new->pos++;
		else if (new->content < stack->content)
			stack->pos++;
		stack = stack->next;
	}
}

t_push	*ft_init_push(t_push *push)
{
	push = (t_push *)malloc(sizeof(t_push));
	if (push == NULL)
		exit(1);
	push->a = NULL;
	push->b = NULL;
	push->split = NULL;
	push->moves = 0;
	push->len_a = 0;
	push->len_b = 0;
/* 	push->max_a = 0;
	push->max_b = 0;
	push->min_a = 0;
	push->min_b = 0; */
	push->posmax_a = 0;
	push->posmin_a = 0;
	push->posmax_b = 0;
	push->posmin_b = 0;
	return (push);
}
void	ra_rra(t_stack **stack_a, t_push *push, int pos)
{
	if (pos < (push->len_a / 2))
		r_swap(stack_a, 'a', push);
	else
		r_swap(stack_a, 'a', push);
}

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

void	p_swap(t_stack **stacka, t_stack **stackb, char c, t_push *push)
{
	t_stack	*temp;

	if (stacka == NULL)
		return ;
	
		temp = (*stacka);
		(*stacka) = (*stacka)->next;
		temp->next = *stackb;
		*stackb = temp;
		print_and_moves_p(push, c);
		printf("MAMAHUEVO\n");
	return ;
}

void	rr_rev_swap(t_stack **stack1, t_stack **stack2, t_push *push)
{
	r_rev_swap(stack1, 'w', push);
	r_rev_swap(stack2, 'w', push);
	printf("rrr\n\n");
	push->moves++;
}

void	r_swap(t_stack **stack, char c, t_push *push)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack)
	{
		tmp = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		*stack = tmp->next;
		tmp->next = NULL;
		last->next = tmp;
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

void	pos_num_max(t_stack *stack, t_push *push, char c)
{
	push->posmax_a = 0;
	push->posmax_b = 0;
	ft_maximo(stack, push, c);
	if (c == 'a' && push->len_a != 0)
	{
		while (stack->content != push->max_a)
		{
			push->posmax_a++;
			stack = stack->next;
		if (stack->next == NULL)
			return ;
		}
	}
	if (c == 'b' && push->len_b != 0)
	{
		while (stack->content != push->max_b)
		{
			push->posmax_b++;
			stack = stack->next;
		}
	}
}

void	pos_num_min(t_stack *stack, t_push *push, char c)
{
	push->posmin_a = 0;
	push->posmin_b = 0;
	ft_minimo(stack, push, c);
	if (c == 'a' && push->len_a != 0)
	{
		while (stack->content != push->min_a)
		{
			push->posmin_a++;
			stack = stack->next;
		if (stack->next == NULL)
			return ;
		printf("el minimo\n");
		}
	}
	if (c == 'b' && push->len_b != 0)
	{
		while (stack->content != push->min_b)
		{
			push->posmin_b++;
			stack = stack->next;
		}
	}
}

void	posmaxmin(t_stack *stack, t_push *push, char c)
{
	pos_num_min(stack, push, c);
	pos_num_max(stack, push, c);
}
void	print_and_moves_s(t_push *push, char c)
{
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
	push->moves++;
}

void	print_and_moves_p(t_push *push, char c)
{
	if (c == 'b')
	{
		printf("tamaño len a%d\n", push->len_a);
		printf("tamaño len b%d\n", push->len_b);
		push->len_a -= 1;
		push->len_b += 1;
		printf("tamaño len a%d\n", push->len_a);
		printf("tamaño len b%d\n", push->len_b);
		printf("El sengundo nodo de B es : %d\n", push->b->next->content);
		printf("pb\n");
		printf("El primer nodo de B es : %d\n", push->b->content);
		return ;
	}
	else if (c == 'a')
	{
		push->len_a += 1;
		push->len_b -= 1;
		printf("pa\n");
	}
	push->moves++;
}

void	print_and_moves_r(t_push *push, char c)
{
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
	push->moves++;
}

void	print_and_moves_w(t_push *push, char c)
{
	if (c == 'a')
		printf("rra\n");
	else if (c == 'b')
		printf("rrb\n");
	push->moves++;
}

t_stack	*ft_lstnew_ps(int content)
{	
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
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
	return ;
}

void	ft_lstiter_ps(t_stack *lst)
{
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
	}
}

void	put_arg_to_int(t_stack **stack, char **av, t_push *push)
{
	int		i;
	int		num;
	int		j;
	char	**temp;
	t_stack	*new;

	i = 0;
	if (push)
	{
		while (av[++i] != NULL)
		{
			j = -1;
			temp = ft_split(av[i], ' ');
			while (temp[++j])
			{
				num = atoi_ps(temp[j]);
				new = ft_lstnew_ps(num);
				ft_lstadd_back_ps(stack, new);
			}
			position_nums((*stack), new);
			free(temp);
		}
	}
}

void	push_swap(t_stack **stack, char **av, t_push *push)
{
	put_arg_to_int(stack, av, push);
}

int	main(int ac, char *av[])
{
	t_push	*push;
/* 	t_push	*tmp; */

	push = NULL;
	if (ac < 2)
		exit_ps("need-arg");
	else
	{
		push = ft_init_push(push);
		push_swap(&(push->a), av, push);
		push->len_a = count_nums(push->a);
		printf("\nNodo: %d   Pos: %d\n", push->a->content, push->a->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->content, push->a->next->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->content, push->a->next->next->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->next->content, push->a->next->next->next->pos);
		printf("\nNodo: %d   Pos: %d\n\n\n", push->a->next->next->next->next->content, push->a->next->next->next->next->pos);
		algo_5(&push->a, &push->b, push);
		printf("\nNodo: %d   Pos: %d\n", push->a->content, push->a->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->content, push->a->next->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->content, push->a->next->next->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->next->content, push->a->next->next->next->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->next->next->content, push->a->next->next->next->next->pos);
		
/* 		printf("Movimientos: %d\n", push->moves);
		count_nums(push->a, push, 'a');
		printf("Tamaño del stack A: %d\n", push->len_a); */

	}
	return (0);
}
