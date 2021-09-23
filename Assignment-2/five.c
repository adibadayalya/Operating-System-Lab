#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main ()
{

  pid_t first_child, second_child, third_child, fourth_child, fifth_child, sixth_child;
  first_child = fork ();
  if (first_child == 0)
    {
      printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (), getppid ());
      wait (NULL);
      third_child = fork ();
      if (third_child == 0)
	{
	  printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (),
		  getppid ());
	  wait (NULL);
	}
      else
	{
	  fourth_child = fork ();
	  if (fourth_child == 0)
	    {
	      printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (),
		      getppid ());
	      wait (NULL);
	    }
	  else
	    {
	      printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (),
		      getppid ());
	      wait (NULL);
	    }
	}
    }
  else
    {
      second_child = fork ();
      if (second_child == 0)
	{
	  printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (),
		  getppid ());
	  wait (NULL);
	  fifth_child = fork ();
	  if (fifth_child == 0)
	    {
	      printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (),
		      getppid ());
	      wait (NULL);
	    }
	  else
	    {
	      sixth_child = fork ();
	      if (sixth_child == 0)
		{
		  printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (),
			  getppid ());
		  wait (NULL);
		}
	      else
		{
		  printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (),
			  getppid ());
		  wait (NULL);
		}
	    }
	}
      else
	{
	  printf ("[CHILD] pid %d from [PARENT] pid %d\n", getpid (),
		  getppid ());
	  wait (NULL);
	}
    }
}
