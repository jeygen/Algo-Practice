/*
This command is invoked with `d', optionally followed by the name of a state to delete. 
When the ‘d’ command is invoked without the optional argument, 
it should delete (i.e. mark as “deleted”) all un-deleted states that are unreachable. 
If there are no such unreachable un-deleted states, it should print:

No states deleted.

Otherwise, it should print the message:

Deleted: <list of deleted states>

If the ‘d’ command is followed by an argument that it the valid name of a state, 
it should print out either the message:

Deleted.

if the state is not reachable and not already deleted. Otherwise, it should print out the message:

Not deleted.

If a state is successfully deleted, it should no longer appear in the list of states produced
by the print command and it should be disallowed as a final argument to the change command.
*/

#include <stdio.h>
#include <stdlib.h>
#include "commands.h"