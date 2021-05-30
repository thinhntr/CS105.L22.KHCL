const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(
  75,
  window.innerWidth / window.innerHeight,
  0.1,
  1000
);

camera.position.z = 10;
camera.position.y = 0;
camera.position.z = 30;

const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Torus shape

const geometry = new THREE.TorusGeometry(10, 3, 16, 100);
const material = new THREE.MeshStandardMaterial({ color: 0x8e24aa });
const torus = new THREE.Mesh(geometry, material);
scene.add(torus);

// Lightning

const pointLight = new THREE.PointLight(0xffffff);
const ambientLight = new THREE.AmbientLight(0xffffff);
pointLight.position.set(5, 5, 5);
scene.add(pointLight, ambientLight);

// Background

const spaceTexture = new THREE.TextureLoader().load("space.jpg");
scene.background = spaceTexture;

// Cube avatar

const thinhTexture = new THREE.TextureLoader().load("uit_avatar.jpg");
const cubeAvatar = new THREE.Mesh(
  new THREE.BoxGeometry(3, 3, 3),
  new THREE.MeshBasicMaterial({ map: thinhTexture })
);

scene.add(cubeAvatar);

// Render

const animate = function () {
  requestAnimationFrame(animate);

  torus.rotation.x += 0.01;
  torus.rotation.y += 0.01;
  torus.rotation.z += 0.01;

  cubeAvatar.rotation.x -= 0.01;
  cubeAvatar.rotation.y -= 0.01;
  cubeAvatar.rotation.z -= 0.01;

  renderer.render(scene, camera);
};

animate();
