
void	ft_swap_link(void **a, void **b)
{
	void *c;

	if (!a || !b)
		return ;
	c = *a;
	*a = *b;
	*b = c;
}
