#include "slide_line.h"

/**
 * slide_line - s
 * @line: l
 * @size: s
 * @direction: d
 * Return: 1
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((direction != 0 && direction != 1) || (line == NULL || size < 1))
	{
		return (0);
	}
	if (direction == 0)
	{
		int idx, postt = 0, nam = 0;

		for (idx = 0; idx < (int)size; idx++)
		{
			if (line[idx] == 0)
				postt++;
			if (line[idx] > 0)
				nam++;
			if (line[idx] > 0 && postt > 0)
			{
				line[idx - postt] = line[idx];
				line[idx] = 0;
				idx = idx - postt;
				postt = 0;
			}
		}
		postt = 0;
		for (idx = 0; idx < nam; idx++)
		{
			if (idx < nam - 1 && line[idx] == line[idx + 1])
			{
				line[postt] = line[idx] + line[idx + 1];
				line[idx + 1] = 0;
				if (postt != idx)
					line[idx] = 0;
				postt++;
			}
			else if (line[idx] > 0 && postt > 0)
			{
				line[postt] = line[idx];
				if (postt != idx)
					line[idx] = 0;
				postt++;
			}
			else if (line[idx] > 0)
				postt++;
		}
	}
	if (direction == 1)
	{
		int idx, pst = 0, mxim = size - 1, nam = 0;

		for (idx = mxim; idx >= 0; idx--)
		{
			if (line[idx] == 0)
				pst++;
			if (line[idx] > 0)
				nam++;
			if (line[idx] > 0 && pst > 0)
			{
				line[idx + pst] = line[idx];
				line[idx] = 0;
				idx = idx + pst;
				pst = 0;
			}
		}
		pst = mxim;
		for (idx = mxim; idx > mxim - nam; idx--)
		{
			if (idx > mxim - nam + 1 && line[idx] == line[idx - 1])
			{
				line[pst] = line[idx] + line[idx - 1];
				line[idx - 1] = 0;
				if (pst != idx)
					line[idx] = 0;
				pst--;
			}
			else if (line[idx] > 0 && pst < mxim)
			{
				line[pst] = line[idx];
				if (pst != idx)
					line[idx] = 0;
				pst--;
			}
			else if (line[idx] > 0)
				pst--;
		}
	}
	return (1);
}
