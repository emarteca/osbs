/**
	Supertype of all types that need to deal with synchro stuff

	The idea: call into KernelMode to change permissions on the types
	So how is this permission going to be represented???
	Maybe rn as just read/write flags on an obj?  Or something similar
*/

typedef enum Mode { UserMode = 0, KernelMode = 1} Mode;
typedef enum PWType { CanWrite = 0, CantWrite = 1} PRType;

// better way of doing types would be to have combos, maybe tuples?

class ChangObj {
	
	private: 
		Mode curMode; 
		PRType writePerm; // maybe this could be per field idk

	public:
		const Mode getCurMode() const { return curMode; }
		bool enterKernelMode(); // return true if did, false if error
		bool exitKernelMode();  // should this function exist	
		const PRType getReadPerm() const { return readPerm; }

		// need to figure out how to tell if you're allowed to do something
		// while in a particular mode
		// for simple case tested here, no write means you can't change 
		// the values of any fields; basically it means you can only call
		// methods that are const on the object
		bool canCallThis() const;

		// to tell: when any method is called on an obj, it needs to be 
		// checked whether it can be called first
		// so, need to figure out if the method being called is const or not

		// also, for this to work there needs to be a way to change the 
		// permissions of an obj, i.e. a reason to change them, and a user
		// to instigate the change

		// another thing to consider is maybe setting it up so the permissions
		// are wrt the user, as in the typestates convo we had at some point
		// but rn let's stick with this model

		// how do we know if we can change permissions?
		// 
}; 
