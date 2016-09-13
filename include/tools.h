#pragma once

#include "mat.h"

void getPosition(Mat <int> &m, int &get_row_start_index , int &get_col_start_index,
				 int &get_row_goal_index , int &get_col_goal_index);
void putDistance(Mat <int> &m);
bool checkAvailable(Mat <int> &m, int r, int c);
void setPathDistance(Mat <int> &m, int &get_row_start_index , int &get_col_start_index,
					 int &get_row_goal_index , int &get_col_goal_index);

void drawPath(Mat <int> &m, int &get_row_start_index , int &get_col_start_index,
			  int &get_row_goal_index , int &get_col_goal_index);

void drawNewMap( Mat < unsigned char> &m, Mat <int> &m1 );