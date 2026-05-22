#ifndef PUSH_SWAP_2_H
# define PUSH_SWAP_2_H


int		*list_to_arr(t_stack *a);
void	ft_shell_sort(int	*arr, int	n);
void	ft_stack_put_index(t_stack *a);
int		*ft_list_to_arr(t_stack *a);
int		ft_sqrt(int nb);
int		ft_find_best_pos(t_stack *s, int current_chank_limit);
int		ft_find_index_pos(t_stack *b, int target_index);
void	ft_chunk_sort(t_stack **a, t_stack **b, t_command *comms);
void	ft_shell_sort(int *arr, int n);
void	ft_insertion_sort(t_stack **a, t_stack **b, t_command *commands);
int		ft_get_chunk_size(int stack_len);

#endif