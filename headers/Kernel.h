#ifndef KERNEL_H
#define KERNEL_H

#include "thread_pool.hpp"


namespace blood_engine {
	class Kernel {


	public:

		virtual void Run();



	private:
		thread_pool pool;



	};

}
#endif // !KERNEL_H
