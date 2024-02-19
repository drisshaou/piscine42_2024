/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrapper.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:41:39 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/18 20:41:44 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAPPER_H
# define SCRAPPER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_p
{
	int	*colup;
	int	*coldown;
	int	*rowleft;
	int	*rowright;
}	t_p;

void	start(int **tab, t_p *s);
void	create_struct(int **tab, t_p *s);
int		allocate_memory(char *av);
int		parsing(t_p *s, char *av);
void	print_error(void);
void	free_tab(int **tab, int size);
int		is_tab_valid(int **tab);
void	free_sides(t_p *s);
void	show_tab(int **tab);
int		is_arg_valid(char *str);
int		check_sides_occur(int *occur);
int		is_parse_valid(int *side1, int *side2);
void	parse_arg(char *s, int *side1, int *side2);
void	init_tab(int **tab);
void	fill_with_three(int **tab, int *side1, int *side2, int flip);
void	fill_with_two_bottom(int **tab, int *side1, int *side2, int flip);
void	fill_with_two_top(int **tab, int *side1, int *side2, int flip);
void	fill_with_one_from_bottom(int **tab, int *side1, int *side2, int flip);
void	fill_with_one_from_top(int **tab, int *side1, int *side2, int flip);
void	fill_with_four1(int **tab, int *side1, int *side2, int flip);
void	fill_with_four(int **tab, int *side1, int *side2, int flip);
int		is_valid(int **tab, int row, int col, int val);
int		check_tab_occur(int **tab, int val);
void	fill_the_fourth(int **tab);
void	fill_the_missing_in_row2(int **tab, int row);
void	fill_the_missing_in_row(int **tab);
void	fill_the_missing_in_col(int **tab);
void	fill_row_col_from_bottom(int **tab, int *side2, int flip);
void	fill_row_col_from_top(int **tab, int *side1, int *side2, int flip);

#endif
