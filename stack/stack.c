#include <stdio.h>
#include <stdlib.h>


struct stack
{
	int item;
	struct stack *next_frame;
};


struct stack *
push (struct stack *frame, int item)
{

	struct stack *p_frame;

	if (frame == NULL)
	  {
		frame = malloc (sizeof (struct stack));
		frame->item = item;
		frame->next_frame = NULL;
	  }
	else
	  {
		p_frame = malloc (sizeof (struct stack));
		p_frame->item = item;
		p_frame->next_frame = frame;
		frame = p_frame;
	  }

	printf ("\nItem: %d - Address: %p - Adicionado!!\n\n", frame->item, frame->next_frame);

	return frame;
}


void
list_stack (struct stack *frame)
{
	/*
	 * pointer to a frame
	 */
	struct stack *p_frame;

	if (frame != NULL)
	  {
		p_frame = frame;
		printf ("\nItem: %d - Address: %p - Next: %p \n", p_frame->item, p_frame, p_frame->next_frame);

		while (p_frame->next_frame)
		  {
			p_frame = p_frame->next_frame;
			printf ("Item: %d - Address: %p - Next: %p \n", p_frame->item, p_frame, p_frame->next_frame);
		  }
	  }

	printf("\n");
} 


int
search_by_item (struct stack *frame, int item)
{
	struct stack *p_frame, *p_next_frame;
	int position = -1;
	int frame_counter = 0;

	if (frame)
	  {
		p_frame = frame;
		p_next_frame = p_frame;

		while (p_next_frame)
		  {

			 if (p_frame->item != item)
			   {
				p_frame = p_frame->next_frame;
				p_next_frame = p_frame;
				frame_counter++;
			   }
			 else
			   {
				 position = (frame_counter +1);
				 p_next_frame = NULL; /* to exit loop */
			   }
		  }
	  }

	return position;
} 

int
stack_size (struct stack *frame)
{
	int frame_counter = 0;
	struct stack *p_frame;

	p_frame = frame;

	while (p_frame != NULL)
	  {
		frame_counter++;
		p_frame = p_frame->next_frame;
	  }

	printf ("\nSize of stack: %d  \n\n", frame_counter);

	return frame_counter;
}

struct stack *
remove_by_value (struct stack *frame, int item)
{
	int position, total_frames;
	int frame_counter = 0;
	struct stack *p_frame = frame;


	position = search_by_item (frame, item);

	total_frames = stack_size (frame);

	position--; /* subtract 1 because begins count before zero */


	if (position >= 0) /* negative position: not found item in the stack */
	  {
		if (position == 0) /* first item to be deleted  */
		  {
			frame = p_frame->next_frame; /* stack start at next_frame */
		  }
		else if ((position+1) == total_frames) /* last frame to be deleted */
		  {

			while (frame_counter < (total_frames -2)) /* loop until penult frame, -2 because start with 0 */
			  {
				frame = frame->next_frame;

				printf ("Item: %d - Address: %p \n", frame->item,  frame);

				frame_counter++;

			  }

			frame->next_frame = NULL; /* after while, next_frame is the last one, so assigns NULL */

			frame = p_frame; /* reposition frame to start at the begin */
		  }
		else
		  {
			p_frame = frame; /* loop stack to find the previous one to be deleted */

			while (p_frame)
			  {
				if (frame_counter == position-1) /* enter when find the previous one */
				  {
					p_frame->next_frame = p_frame->next_frame->next_frame; /* points to next_frame that will be deleted */
					break; /* frame delete, stop looping the stack */
				  }

				frame_counter++;

				p_frame = p_frame->next_frame;
			  }
		  }
	  }
	else
	  {
		printf ("\nThis item cannot be found on this stack. \n");
	  }

	return frame;
}



