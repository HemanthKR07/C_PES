import React, { useState } from 'react';
import TaskForm from './TaskForm';
import TaskList from './TaskList';

const App = () => {
  const [tasks, setTasks] = useState([
    { id: 1, description: 'Task 1', category: 'Work', completed: false },
    { id: 2, description: 'Task 2', category: 'Home', completed: false },
    { id: 3, description: 'Task 3', category: 'Hobby', completed: false },
  ]);
  const [currentTask, setCurrentTask] = useState(null);

  const addTask = (task) => {
    setTasks([...tasks, { ...task, id: tasks.length + 1 }]);
  };

  const editTask = (task) => {
    setTasks(tasks.map(t => (t.id === task.id ? task : t)));
  };

  const deleteTask = (id) => {
    setTasks(tasks.filter(task => task.id !== id));
  };

  const toggleComplete = (id) => {
    setTasks(tasks.map(task => (task.id === id ? { ...task, completed: !task.completed } : task)));
  };

  return (
    <div className="container mx-auto p-4">
      <h1 className="text-2xl font-bold mb-4">Todo List</h1>
      <TaskForm addTask={addTask} editTask={editTask} currentTask={currentTask} setCurrentTask={setCurrentTask} />
      <TaskList tasks={tasks} deleteTask={deleteTask} toggleComplete={toggleComplete} setCurrentTask={setCurrentTask} />
    </div>
  );
};

export default App;