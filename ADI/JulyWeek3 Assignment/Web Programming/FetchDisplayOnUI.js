const usersDiv = document.getElementById("users");

const worker = new Worker("worker.js");

worker.postMessage("fetch");

worker.onmessage = function (event) {
    const data = event.data;

    if (!data.success) {
        usersDiv.innerHTML = data.message;
        return;
    }

    usersDiv.innerHTML = "";

    data.users.forEach(user => {
        const p = document.createElement("p");
        p.textContent = `${user.name} - ${user.active ? "Active" : "Inactive"}`;
        usersDiv.appendChild(p);
    });
};

worker.onerror = function () {
    usersDiv.innerHTML = "Error fetching users.";
};
