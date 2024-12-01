function toggleInfo() {
    const info = document.getElementById("info");
    if (info.style.display === "none") {
      info.style.display = "block";
    } else {
      info.style.display = "none";
    }
  }
  function openModal(src) {
    const modal = document.getElementById("modal");
    const modalImg = document.getElementById("modal-img");
    modal.style.display = "block";
    modalImg.src = src;
  }
  
  function closeModal() {
    document.getElementById("modal").style.display = "none";
  }
  const customIcon = L.icon({
    iconUrl: 'https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d12367465.273921438!2d2.1117474981127073!3d40.81916147258839!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x12d4fe82448dd203%3A0xe22cf55c24635e6f!2sItaly!5e0!3m2!1sen!2sbr!4v1727539064650!5m2!1sen!2sbr', 
    iconSize: [38, 38], 
    iconAnchor: [22, 38], 
    popupAnchor: [-3, -38] 
  });
  
  L.marker([-23.55052, -46.633308], { icon: customIcon }).addTo(map)
    .bindPopup("Custom Icon Marker");
    map.on('click', function(e) {
  alert("Você clicou nas coordenadas: " + e.latlng);
});
map.on('click', function(e) {
    alert("Você clicou nas coordenadas: " + e.latlng);
  });
  document.getElementById('feedback-form').addEventListener('submit', function (event) {
    event.preventDefault();
    const name = document.getElementById('name').value.trim();
    const email = document.getElementById('email').value.trim();
    const message = document.getElementById('message').value.trim();
    const status = document.getElementById('feedback-status');
    if (name && email && message) {
      status.textContent = 'Obrigado pelo seu feedback!';
      status.style.color = 'green';
      this.reset();
    } else {
      status.textContent = 'Por favor, preencha todos os campos.';
      status.style.color = 'red';
    }
  });
