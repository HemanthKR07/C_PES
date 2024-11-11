import React, { useState } from 'react';

const styles = {
  completed: {
    textDecoration: 'line-through',
    color: 'gray'
  },
  incomplete: {
    textDecoration: 'none',
    color: 'black'
  },
  container: {
    display: 'flex',
    flexDirection: 'column',
    alignItems: 'center',
    justifyContent: 'center',
    minHeight: '100vh',
    textAlign: 'center'
  },
  taskList: {
    listStyleType: 'none',
    padding: 0
  }
};

function App() {
  const [tasks, setTasks] = useState([
    { id: 1, description: 'Task 1', category: 'Work', completed: false, timestamp: new Date().toLocaleString() },
    { id: 2, description: 'Task 2', category: 'Home', completed: false, timestamp: new Date().toLocaleString() },
    { id: 3, description: 'Task 3', category: 'Hobby', completed: false, timestamp: new Date().toLocaleString() }
  ]);
  const [newTask, setNewTask] = useState({ description: '', category: '' });
  const [isEditing, setIsEditing] = useState(false);
  const [currentTask, setCurrentTask] = useState(null);

  const handleInputChange = (e) => {
    const { name, value } = e.target;
    setNewTask({ ...newTask, [name]: value });
  };

  const handleAddTask = () => {
    if (isEditing) {
      setTasks(tasks.map(task => task.id === currentTask.id ? { ...currentTask, ...newTask } : task));
      setIsEditing(false);
      setCurrentTask(null);
    } else {
      setTasks([...tasks, { ...newTask, id: tasks.length + 1, completed: false, timestamp: new Date().toLocaleString() }]);
    }
    setNewTask({ description: '', category: '' });
  };

  const handleEditTask = (task) => {
    setIsEditing(true);
    setCurrentTask(task);
    setNewTask({ description: task.description, category: task.category });
  };

  const handleDeleteTask = (taskId) => {
    setTasks(tasks.filter(task => task.id !== taskId));
  };

  const handleToggleComplete = (taskId) => {
    setTasks(tasks.map(task => task.id === taskId ? { ...task, completed: !task.completed } : task));
  };

  return (
    <div className="App" style={styles.container}>
      <header className="App-header">
        <h1>Todo List</h1>
        <div>
          <input
            type="text"
            name="description"
            placeholder="Task Description"
            value={newTask.description}
            onChange={handleInputChange}
          />
          <input
            type="text"
            name="category"
            placeholder="Category"
            value={newTask.category}
            onChange={handleInputChange}
          />
          <button onClick={handleAddTask}>{isEditing ? 'Update Task' : 'Add Task'}</button>
        </div>
        <ul style={styles.taskList}>
          {tasks.map(task => (
            <li key={task.id} style={task.completed ? styles.completed : styles.incomplete}>
              {task.description} - {task.category} <br />
              <small>{task.timestamp}</small>
              <div>
                <button onClick={() => handleToggleComplete(task.id)}>
                  {task.completed ? 'Mark Incomplete' : 'Mark Complete'}
                </button>
                <button onClick={() => handleEditTask(task)}>Edit</button>
                <button onClick={() => handleDeleteTask(task.id)}>Delete</button>
              </div>
            </li>
          ))}
        </ul>
      </header>
    </div>
  );
}

export default App;