#include <"ChangObj.h">

/**
	The idea: implement a language where types can be changed with system calls to the kernel.
	I'm thinking types might actually be permissions here...

	Or, it could be that the kernel is the only one allowed to do updates to fields?

	The point: synchronization.  Basically, the idea would be that for threading purposes you'd 
	want to make sure there are no race conditions for object mutations.  This could be solved 
	by a lock, but another idea would be to use a kernel to do all the updates.

	This seems like it would probably be slower?  Maybe?  But hey why not try it.

	Base: kernel in OS, and how some calls switch into "kernel mode" to avoid users messing with
	important data.
*/

class Kernel {
	
	private: 
		int lock; // this probably shouldn't be an int, hmmm
		int exitKernelMode(); // probably called automatically after kernel mode is done?  hence a private method (no one else should be able to call it)

	public:
		Kernel();
		bool enterKernelMode(); // get lock (???); return 1 if entered, 0 if not entered
		bool doIHavePermission(ChangObj c) const;	
};