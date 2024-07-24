// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <sys/time.h>
// #include <unistd.h>

// typedef struct s_philo
// {
//     int id;
//     int time_to_die;
//     int time_to_eat;
//     int time_to_sleep;
//     int number_of_times_to_eat;
//     long long last_meal_time;
//     int meals_eaten;
//     pthread_mutex_t *left_fork;
//     pthread_mutex_t *right_fork;
//     pthread_mutex_t *print_mutex;
//     int *is_dead;
// } t_philo;

// long long	get_time(void)
// {
//     struct timeval	tv;

//     gettimeofday(&tv, NULL);
//     return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
// }

// void	print_status(t_philo *philo, char *status)
// {
//     pthread_mutex_lock(philo->print_mutex);
//     if (!(*philo->is_dead))
//         printf("%lld %d %s\n", get_time(), philo->id, status);
//     pthread_mutex_unlock(philo->print_mutex);
// }

// void	*philosopher(void *arg)
// {
//     t_philo *philo = (t_philo *)arg;

//     while (!(*philo->is_dead))
//     {
//         // Thinking
//         print_status(philo, "is thinking");

//         // Eating
//         pthread_mutex_lock(philo->left_fork);
//         print_status(philo, "has taken a fork");
//         pthread_mutex_lock(philo->right_fork);
//         print_status(philo, "has taken a fork");

//         print_status(philo, "is eating");
//         philo->last_meal_time = get_time();
//         usleep(philo->time_to_eat * 1000);
//         philo->meals_eaten++;

//         pthread_mutex_unlock(philo->left_fork);
//         pthread_mutex_unlock(philo->right_fork);

//         // Sleeping
//         print_status(philo, "is sleeping");
//         usleep(philo->time_to_sleep * 1000);
//     }
//     return (NULL);
// }

// // Main function and other necessary functions to be implemented

// int main(int argc, char **argv)
// {
//     // Check arguments and initialize data structures
//     // Create threads for philosophers
//     // Monitor philosophers' status
//     // Clean up and exit
//     return (0);
// }

// #include <stdio.h>
// #include <pthread.h>

// int l_flous = 1000; // had l'flous huma shared resource
// pthread_mutex_t l_mutex;

// void *chri_7wayej(void *arg)
// {
//     int chhal_srift = *(int*)arg;

//     pthread_mutex_lock(&l_mutex);  // Se9em l'bab

//     // Critical section
//     if (l_flous >= chhal_srift)
//     {
//         l_flous -= chhal_srift;
//         printf("Chrit b %d. Ba9i 3ndi %d\n", chhal_srift, l_flous);
//     }
//     else
//     {
//         printf("Ma3ndich flous bzzaf! Bghit %d walakin 3ndi ghir %d\n",
	chhal_srift, l_flous);
	//     }

	//     pthread_mutex_unlock(&l_mutex);  // 7el l'bab

	//     return (NULL);
	// }

	// int main()
	// {
	//     pthread_t thread1, thread2;
	//     int prix1 = 300, prix2 = 500;

	//     pthread_mutex_init(&l_mutex, NULL);  // Initialiser l'mutex

	//     pthread_create(&thread1, NULL, chri_7wayej, &prix1);
	//     pthread_create(&thread2, NULL, chri_7wayej, &prix2);

	//     pthread_join(thread1, NULL);
	//     pthread_join(thread2, NULL);

	//     pthread_mutex_destroy(&l_mutex);  // Destroy l'mutex

	//     printf("Lflous li b9aw f lekher: %d\n", l_flous);

	//     return (0);
	// }

	// #include <pthread.h>
	// #include <stdio.h>
	// #include <unistd.h>

	// void *ma_fonction(void *arg)
	// {
	//     pthread_t tid = pthread_self();  // Kanjibo l'ID dyal thread
	//     printf("Ana thread: %lu\n", (unsigned long)tid);
	//     sleep(1);
	//     return (NULL);
	// }

	// int main()
	// {
	//     pthread_t thread1, thread2;

	//     pthread_create(&thread1, NULL, ma_fonction, NULL);
	//     pthread_create(&thread2, NULL, ma_fonction, NULL);

	//     printf("Thread 1 ID: %lu\n", (unsigned long)thread1);
	//     printf("Thread 2 ID: %lu\n", (unsigned long)thread2);

	//     pthread_join(thread1, NULL);
	//     pthread_join(thread2, NULL);

	//     return (0);
	// }

	// #include <pthread.h>
	// #include <stdio.h>
	// #include <unistd.h>

	// pthread_mutex_t l_mutex;

	// void *khdem(void *arg)
	// {
	//     int id = *(int*)arg;

	//     printf("Thread %d: kan7awel ndkhol\n", id);
	//     pthread_mutex_lock(&l_mutex);

	//     printf("Thread %d: dkhelt l critical section\n", id);
	//     sleep(2);  // Simulation dyal chi khedma

	//     printf("Thread %d: ghadi nkhrej\n", id);
	//     pthread_mutex_unlock(&l_mutex);

	//     return (NULL);
	// }

	// int main()
	// {
	//     pthread_t thread1, thread2, thread3, thread4;
	//     int id1 = 1, id2 = 2, id3 = 3, id4 = 4;

	//     pthread_mutex_init(&l_mutex, NULL);

	//     pthread_create(&thread1, NULL, khdem, &id1);
	//     sleep(1); 
		// Bach n assurer anna thread1 ghadi yakhod l-mutex l-ewwel
	//     pthread_create(&thread2, NULL, khdem, &id2);
	//     pthread_create(&thread3, NULL, khdem, &id3);
	//     sleep(1);
	//     pthread_create(&thread4, NULL, khdem, &id4);

	//     pthread_join(thread1, NULL);
	//     pthread_join(thread2, NULL);
	//     pthread_join(thread3, NULL);
	//     pthread_join(thread4, NULL);

	//     pthread_mutex_destroy(&l_mutex);

	//     return (0);
	// }