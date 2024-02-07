import style from './AdminSessionsManage.module.css'
import { useNavigate } from "react-router-dom"

const AdminSessionsManage = () => {
  const navigate = useNavigate();

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          Sessions management
        </div>
        <div className={style.imageBox}>
          <div>
            <img src="edu.png" alt="Education.png" onClick={ ()=>navigate('/admin-sessions-view')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/admin-sessions-view')}> Education (x)</div>
          </div>
          <div>
            <img src="psycho.png" alt="Psychological.png" onClick={ ()=>navigate('/admin-sessions-view')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/admin-sessions-view')}>Psychological (y)</div>
          </div>
          <div>
            <img src="funny.png" alt="Funny.png" onClick={ ()=>navigate('/admin-sessions-view')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/admin-sessions-view')}>Funny (z)</div>
          </div>
        </div>
      </div>
  );
}

export default AdminSessionsManage;
