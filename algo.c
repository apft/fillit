/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:05:38 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/20 17:05:46 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//je pose ma piece dans la map
void	place_tile(t_tile tile, t_map map)
{
	soit t index tile
	int	i;
	i = 0;
	while (i < tiles[t].height)
		map[tetri.row + i] |= tetri.lines[i++] >> tetri.col;
}

//je vérifie si je peux poser ma piece dans ma map
int		check_fit(t_tile tetri, unsigned short *map)
{
	int ok = 1;
	while (i < tetri.height && ok)
		if (tetri.lines[i] >> tetri.col & map[tetri.row + i]) // ca coince
			ok = 0; // je ne peux pas poser ma piece	
}


// si le tetri rentre
if (check_fit(tile[t], map))
	// je le mets dans la map
	place_tile(tile[t], map);
	if (t = k) // j'ai réussi à placer le dernier tetri
	{
		final_map = (char *)malloc(sizeof(char) * map_size)
		fill_final_map(final_map, t);
		state.ret = 1;
		return (state); // je renvoie 1
	}
	// sinon je passe au tetri suivant
	if (backtrack(tile[t + 1], map).state) // je renvoie 1 (dernier tetris placé)
	{
			
	}
				

// si le tetri ne rentre pas, je teste la colonne suivante
else if (tile[t].col + tile[t].width < map.map_size) // si col + 1 + (width - 1) < map_size
{
	tile[t].col++;
	backtrack(tile[t], map);
}
// si je suis au max des colonnes, je passe à la ligne suivante
else if (tile[t].row + tile[t].height < map.map_size) // si row + 1 + (height - 1) < map_size
{
	tile[t].col = 0;
	tile[t].row++;
	backtrack(tile[t], map);
}
// si je ne peux pas placer la piece je renvoie 0
else
		return (0)
	


